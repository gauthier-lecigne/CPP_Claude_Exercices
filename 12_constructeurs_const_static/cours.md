# 12 — Constructeurs, `const`, `static` et destructeur

## 1. La liste d'initialisation

Jusqu'ici, on initialisait les attributs dans le corps du constructeur :

```cpp
Gare::Gare(const std::string& nom, int nbQuais) {
    this->nom = nom;          // affectation
    this->nbQuais = nbQuais;
}
```

La forme recommandée est la **liste d'initialisation**, entre `:` et `{` :

```cpp
Gare::Gare(const std::string& nom, int nbQuais)
    : nom(nom), nbQuais(nbQuais) {
}
```

Pourquoi la préférer :

1. **Efficacité** : les attributs sont construits **directement** avec la bonne valeur, au lieu d'être construits vides puis réaffectés.
2. **Obligatoire** pour :
   - les attributs `const` (`const std::string id;`) : on ne peut pas les affecter après coup ;
   - les attributs références (`Ligne& ligne;`) ;
   - les attributs objets sans constructeur par défaut (un attribut `Horaire depart;` alors que `Horaire` n'a pas de constructeur sans paramètre).
3. Pas d'ambiguïté de nom : dans `nom(nom)`, le premier est forcément l'attribut, le second le paramètre.

⚠️ Les attributs sont initialisés **dans l'ordre où ils sont déclarés dans la classe**, pas dans l'ordre de la liste. Écris la liste dans le même ordre pour éviter les surprises (`-Wall` t'avertit).

On peut encore faire des vérifications dans le corps :

```cpp
Gare::Gare(const std::string& nom, int nbQuais)
    : nom(nom), nbQuais(nbQuais > 0 ? nbQuais : 1) {
}
```

## 2. Plusieurs constructeurs

Un constructeur se **surcharge** comme une fonction :

```cpp
class Horaire {
public:
    Horaire();                          // constructeur par défaut : 00:00
    Horaire(int heures, int minutes);
    explicit Horaire(int minutes);      // depuis un nombre de minutes
};
```

**Le constructeur par défaut** (sans paramètre) est celui utilisé par `Horaire h;` ou par `std::vector<Horaire> v(10);`.
⚠️ Dès que tu écris **un** constructeur, le compilateur ne génère plus le constructeur par défaut automatiquement. Pour le récupérer : `Horaire() = default;` ou écris-le.

**Constructeur délégué** : un constructeur peut en appeler un autre pour éviter de répéter le code :

```cpp
Horaire::Horaire() : Horaire(0, 0) {}
```

**`explicit`** : empêche les conversions implicites surprenantes. Sans lui, `Horaire h = 90;` compilerait. Mets `explicit` sur les constructeurs à **un seul** paramètre, sauf si la conversion a vraiment du sens.

## 3. Les attributs par défaut

On peut donner une valeur par défaut directement dans la déclaration :

```cpp
class Train {
private:
    double vitesse = 0.0;
    int retard = 0;
    bool enService = true;
};
```

Ces valeurs sont utilisées si le constructeur ne les initialise pas. C'est pratique et ça évite les attributs non initialisés.

## 4. La « const-correctness »

`const` apparaît à plusieurs endroits, avec des sens différents :

```cpp
class Gare {
public:
    std::string getNom() const;              // (1) méthode qui ne modifie pas l'objet
    void renommer(const std::string& nom);   // (2) paramètre non modifiable
private:
    const int id;                            // (3) attribut fixé à la construction
};

const Gare lyon("Lyon", 4);                  // (4) objet constant
lyon.getNom();     // OK : méthode const
lyon.renommer("x");// ERREUR : méthode non const sur un objet const
```

La règle qui en découle : **un objet `const` (ou passé en `const&`) ne peut appeler que des méthodes `const`.**
Si tu oublies le `const` sur un getter, tu ne pourras pas l'utiliser dans une fonction `void afficher(const Gare& g)`. C'est l'erreur `passing 'const Gare' as 'this' argument discards qualifiers`.

## 5. Les membres `static`

Un attribut `static` est **partagé par tous les objets** de la classe : il n'existe qu'en un exemplaire.

```cpp
// Train.hpp
class Train {
public:
    Train();
    static int getNbTrains();       // méthode static : appelable sans objet
private:
    static int nbTrains;            // déclaration
    int numero;
};

// Train.cpp
int Train::nbTrains = 0;            // définition (obligatoire, une seule fois, dans le .cpp)

Train::Train() : numero(++nbTrains) {}   // chaque train reçoit un numéro unique

int Train::getNbTrains() {          // pas de "static" répété ici
    return nbTrains;
}
```

```cpp
Train a, b, c;
std::cout << Train::getNbTrains();  // 3 : appel via le nom de la classe
```

- Une méthode `static` n'a **pas** de `this` : elle ne peut pas accéder aux attributs non static.
- Pour une constante de classe : `static constexpr double VITESSE_MAX = 320.0;` directement dans le `.hpp`, sans définition dans le `.cpp`.

## 6. Le destructeur

Méthode appelée **automatiquement** quand l'objet est détruit (fin de bloc, `delete`, fin du `unique_ptr`) :

```cpp
class Train {
public:
    ~Train();    // tilde + nom de la classe, pas de paramètre, pas de retour
};

Train::~Train() {
    std::cout << "Train detruit\n";
}
```

```cpp
{
    Train t;     // constructeur
    // ...
}                // destructeur appelé ici, automatiquement
```

Les objets locaux sont détruits **dans l'ordre inverse** de leur création.

Dans la plupart des classes, tu n'as **pas besoin** d'écrire de destructeur : `std::string`, `std::vector`, `std::unique_ptr` se libèrent tout seuls. Il devient indispensable pour :
- libérer une ressource gérée à la main (fichier, connexion…) : c'est le principe **RAII** (*la ressource vit et meurt avec l'objet*) ;
- les classes de base polymorphes (`virtual ~Train()`, chapitre 15) ;
- tenir un compteur `static` à jour (exercice 2).

## 7. Aperçu : surcharger des opérateurs

On peut définir le sens de `+`, `==`, `<<`… pour ses propres classes :

```cpp
// dans la classe Fraction (.hpp)
Fraction operator+(const Fraction& autre) const;
bool operator==(const Fraction& autre) const;

// fonction libre, pour pouvoir écrire std::cout << f
std::ostream& operator<<(std::ostream& out, const Fraction& f);
```

```cpp
Fraction c = a + b;           // appelle a.operator+(b)
std::cout << c << std::endl;  // appelle operator<<(std::cout, c)
```

C'est un bonus dans l'exercice 1 : fais d'abord les méthodes classiques (`additionner`…).

## À retenir

- Liste d'initialisation `: a(x), b(y)` : à utiliser par défaut.
- Écrire un constructeur supprime le constructeur par défaut implicite.
- `explicit` sur les constructeurs à un paramètre.
- Toute méthode qui ne modifie pas l'objet est `const`.
- `static` = partagé par tous les objets ; à définir dans le `.cpp`.
- Destructeur `~Classe()` : rarement nécessaire, appelé automatiquement.
