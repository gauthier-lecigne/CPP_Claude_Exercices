# 14 — L'héritage

La composition exprime « **a un** » (une voiture *a un* moteur).
L'héritage exprime « **est un** » : un TGV *est un* train, un étudiant *est une* personne.

## Le principe

```cpp
class Personne {                       // classe de base (mère)
public:
    Personne(const std::string& nom, int age);
    std::string getNom() const;
    void sePresenter() const;
private:
    std::string nom;
    int age;
};

class Etudiant : public Personne {     // classe dérivée (fille)
public:
    Etudiant(const std::string& nom, int age, const std::string& ecole);
    std::string getEcole() const;
private:
    std::string ecole;                 // ce qu'un Etudiant a EN PLUS
};
```

Un `Etudiant` **hérite** de tout ce qu'a une `Personne` (nom, âge, `getNom()`, `sePresenter()`…) et **ajoute** son école.

```cpp
Etudiant e("Gauthier", 21, "SUPINFO");
e.getNom();       // méthode héritée de Personne
e.getEcole();     // méthode propre à Etudiant
e.sePresenter();  // héritée
```

En UML : une flèche à **triangle vide** de la fille vers la mère (`Etudiant ──▷ Personne`).

## Le test « est un »

Avant d'hériter, pose-toi la question : « Est-ce qu'un B **est un** A, dans **tous** les cas ? »

| Relation | « est un » ? | Choix |
|---|---|---|
| `Etudiant` / `Personne` | Oui | Héritage |
| `HighSpeedTrain` / `Train` | Oui | Héritage |
| `Voiture` / `Moteur` | Non : une voiture *a* un moteur | Composition |
| `Ligne` / `std::vector<Gare>` | Non : une ligne *contient* des gares | Composition |

Hériter pour « récupérer du code » sans vraie relation « est un » est une erreur de conception classique.

## Le constructeur de la classe fille

La classe fille doit **d'abord** construire la partie « mère ». Elle le fait dans sa **liste d'initialisation** :

```cpp
Etudiant::Etudiant(const std::string& nom, int age, const std::string& ecole)
    : Personne(nom, age),    // (1) appel du constructeur parent, EN PREMIER
      ecole(ecole) {         // (2) puis ses propres attributs
}
```

- Si `Personne` n'a pas de constructeur par défaut, cet appel est **obligatoire**.
- Ordre de construction : **mère puis fille**. Ordre de destruction : **fille puis mère**.
- Raccourci quand la fille n'ajoute aucun attribut : `using Personne::Personne;` (vu dans le code des trains).

## `private`, `protected`, `public`

```cpp
class Personne {
public:      // tout le monde
protected:   // Personne ET ses classes filles
private:     // Personne seulement (même pas les filles !)
};
```

```cpp
void Etudiant::afficher() const {
    std::cout << nom;        // ERREUR si nom est private dans Personne
    std::cout << getNom();   // OK : on passe par l'interface publique
}
```

| | La classe | Les filles | L'extérieur |
|---|---|---|---|
| `public` (`+`) | ✅ | ✅ | ✅ |
| `protected` (`#`) | ✅ | ✅ | ❌ |
| `private` (`-`) | ✅ | ❌ | ❌ |

Conseil : garde les attributs **`private`** même dans une classe de base, et donne aux filles des **méthodes** `protected` si elles ont besoin d'un accès particulier. Ainsi la classe mère reste seule garante de ses invariants. (C'est pour ça qu'on a pu passer `Train` de `protected` à `private` sans rien casser.)

## Redéfinir une méthode

Une fille peut fournir sa propre version d'une méthode de la mère :

```cpp
void Etudiant::sePresenter() const {
    Personne::sePresenter();                      // réutilise la version de la mère
    std::cout << "J'etudie a " << ecole << "\n";  // et complète
}
```

`Personne::sePresenter()` appelle explicitement la version de la classe mère : très utile pour **compléter** au lieu de tout réécrire.

⚠️ **Sans `virtual`, cette redéfinition ne marche qu'à moitié** :

```cpp
Etudiant e("Gauthier", 21, "SUPINFO");
Personne& p = e;      // une référence de type Personne vers un Etudiant
p.sePresenter();      // appelle Personne::sePresenter, PAS celle d'Etudiant !
```

Le compilateur choisit la méthode d'après le type de la **variable** (`Personne&`), pas d'après l'objet réel. C'est exactement le problème que `virtual` résout : c'est le sujet du chapitre 15.

## Une fille utilisée comme une mère

Partout où l'on attend une `Personne`, on peut passer un `Etudiant` (il **est** une personne) :

```cpp
void saluer(const Personne& p) {
    std::cout << "Bonjour " << p.getNom() << "\n";
}

Etudiant e("Gauthier", 21, "SUPINFO");
saluer(e);    // OK
```

⚠️ **Le découpage (*slicing*)** : passer **par valeur** coupe la partie fille.

```cpp
void saluerCopie(Personne p);   // copie : seule la partie Personne est copiée
std::vector<Personne> groupe;   // même problème : on ne stocke que des Personne
groupe.push_back(e);            // l'école est perdue !
```

Avec l'héritage, manipule toujours les objets par **référence** (`Personne&`) ou par **pointeur** (`Personne*`, `std::unique_ptr<Personne>`).

## Plusieurs niveaux

```
Personne
├── Etudiant
│   └── EtudiantAlternant
└── Professeur
```

C'est possible, mais au-delà de 2 ou 3 niveaux le code devient difficile à suivre. Préfère des hiérarchies plates.

## À retenir

- Héritage = « est un ». Sinon, composition.
- `class Fille : public Mere`.
- Le constructeur de la fille appelle celui de la mère **en premier** dans la liste d'initialisation.
- Attributs `private` même dans la mère ; `protected` avec parcimonie.
- `Mere::methode()` pour appeler la version de la mère.
- Manipule les objets d'une hiérarchie par référence ou pointeur, jamais par copie.
- Sans `virtual`, la redéfinition n'est pas polymorphe → chapitre 15.
