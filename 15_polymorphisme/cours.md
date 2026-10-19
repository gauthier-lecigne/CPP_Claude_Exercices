# 15 — Le polymorphisme : `virtual`, `override`, classes abstraites

Au chapitre 14, on a vu le problème : via une `Vehicule*`, c'est toujours la méthode
de `Vehicule` qui est appelée, même si l'objet est un `Camion`. Le polymorphisme
corrige ça, et c'est ce qui rend l'héritage vraiment utile.

## 1. `virtual` : choisir la méthode d'après l'objet réel

```cpp
class Vehicule {
public:
    virtual double tempsTrajet(double km) const;   // virtual dans la classe MÈRE
    virtual ~Vehicule() = default;                 // (voir section 4)
};

class Camion : public Vehicule {
public:
    double tempsTrajet(double km) const override;  // override dans la FILLE
};
```

```cpp
Camion c(...);
Vehicule* v = &c;
v->tempsTrajet(450);   // appelle maintenant Camion::tempsTrajet
```

| | Sans `virtual` | Avec `virtual` |
|---|---|---|
| Ce qui décide | le type de la **variable** (`Vehicule*`) | le type de l'**objet** réel (`Camion`) |
| Quand | à la compilation | à l'exécution |

- `virtual` s'écrit **dans le `.hpp` de la classe mère**, pas dans le `.cpp`.
- Une méthode virtuelle le reste dans toutes les filles.
- Le polymorphisme ne fonctionne **qu'à travers une référence ou un pointeur**. Un objet copié par valeur dans une `Vehicule` est découpé (*slicing*) et redevient un simple `Vehicule`.

## 2. `override` : demander au compilateur de vérifier

```cpp
class Camion : public Vehicule {
    double tempsTrajet(double km) override;   // ERREUR : il manque const !
};
```

Sans `override`, cette faute de frappe créerait **silencieusement** une nouvelle méthode, et c'est celle de `Vehicule` qui continuerait d'être appelée. Avec `override`, le compilateur vérifie qu'une méthode virtuelle de même signature existe dans la mère.

**Mets `override` sur chaque redéfinition, toujours.** `override` va dans le `.hpp` uniquement.

`final` (plus rare) interdit qu'une méthode soit redéfinie plus bas, ou qu'une classe soit héritée : `class TGV final : public Train`.

## 3. Méthodes virtuelles pures et classes abstraites

Que renverrait `Forme::aire()` pour une forme « en général » ? Rien de sensé. On la déclare **virtuelle pure** :

```cpp
class Forme {
public:
    virtual ~Forme() = default;
    virtual double aire() const = 0;        // "= 0" : pas d'implémentation ici
    virtual std::string nom() const = 0;
};
```

- Une classe avec au moins une méthode virtuelle pure est **abstraite** : on ne peut pas créer d'objet `Forme` (`Forme f;` ne compile pas).
- Chaque fille **doit** implémenter toutes les méthodes pures, sinon elle est abstraite à son tour.
- On peut quand même manipuler des `Forme&`, `Forme*`, `std::unique_ptr<Forme>`.

En UML, une classe abstraite et ses méthodes pures s'écrivent en *italique* (ou avec `<<abstract>>`).

Une classe abstraite peut aussi avoir des attributs et des méthodes normales : c'est ce qui la distingue d'une simple « interface ».

## 4. Le destructeur virtuel (indispensable)

```cpp
std::unique_ptr<Forme> f = std::make_unique<Cercle>(2.0);
// à la fin : delete d'un Forme* qui pointe sur un Cercle
```

Si `~Forme()` n'est pas virtuel, seul le destructeur de `Forme` est appelé : la partie `Cercle` n'est pas détruite correctement (comportement indéfini).

**Règle : une classe qui a au moins une méthode `virtual` doit avoir un destructeur `virtual`.**

```cpp
virtual ~Forme() = default;   // "= default" : le compilateur écrit le corps vide
```

## 5. Une collection d'objets différents

C'est **le** cas d'usage du polymorphisme :

```cpp
std::vector<std::unique_ptr<Forme>> formes;
formes.push_back(std::make_unique<Cercle>(1.0));
formes.push_back(std::make_unique<Rectangle>(2.0, 3.0));

double total = 0;
for (const auto& f : formes) {
    std::cout << f->nom() << " : " << f->aire() << "\n";   // la bonne version à chaque fois
    total += f->aire();
}
```

- `unique_ptr` est **obligatoire** ici : un `std::vector<Forme>` ne peut pas contenir de `Cercle` (et `Forme` est abstraite).
- `std::make_unique<Cercle>(1.0)` crée un `Cercle` ; il est converti automatiquement en `unique_ptr<Forme>`.
- La boucle **ne sait pas** quelles formes elle manipule, et n'a pas besoin de le savoir.

## 6. Le vrai bénéfice : ajouter un type sans toucher au reste

Pour ajouter un `Triangle`, on écrit une nouvelle classe fille. **La boucle ci-dessus ne change pas d'une ligne.**

C'est le principe **ouvert/fermé** : le code est *ouvert à l'extension* (nouvelles classes) mais *fermé à la modification* (le code existant ne bouge pas). C'est exactement la règle 5 du projet ferroviaire : « ajouter un train de nuit sans réécrire la simulation ».

La mauvaise alternative, à reconnaître pour l'éviter :

```cpp
if (f.type == "cercle") { ... }
else if (f.type == "rectangle") { ... }   // à modifier partout à chaque nouveau type
```

## 7. Le patron « méthode modèle » (*Template Method*)

Souvent, l'**algorithme** est commun et seuls quelques **détails** changent. On met l'algorithme dans une méthode **non virtuelle** de la mère, qui appelle des méthodes virtuelles :

```cpp
class Train {
public:
    void avancer(int minutes);           // NON virtuelle : l'algorithme est le même pour tous
protected:
    virtual double getVitesseMax() const = 0;    // détail obligatoire
    virtual int getTempsArret() const { return 2; }  // détail avec valeur par défaut
};

void Train::avancer(int minutes) {
    // ... utilise getVitesseMax() et getTempsArret() ...
}

class Fret : public Train {
protected:
    double getVitesseMax() const override { return 100; }
    int getTempsArret() const override { return 10; }   // redéfinit la valeur par défaut
};
```

Avantages : l'algorithme n'est écrit qu'une fois, et une fille ne peut pas le casser ; elle ne fait que fournir des réglages.

## 8. Comment ça marche (pour la culture)

Chaque classe qui a des méthodes virtuelles possède une table cachée, la **vtable**, qui contient l'adresse de ses versions des méthodes. Chaque objet garde un pointeur caché vers la vtable de sa classe. Un appel virtuel suit ce pointeur : c'est pour ça que le choix se fait à l'exécution. Le coût est minime (une indirection).

## 9. `dynamic_cast` (à éviter le plus souvent)

```cpp
if (Cercle* c = dynamic_cast<Cercle*>(f.get())) {
    // f est bien un Cercle
}
```

Ça permet de retrouver le type réel, mais si tu en écris beaucoup, c'est que tu as recréé le `if (type == ...)` : il manque probablement une méthode virtuelle.

## À retenir

- `virtual` dans la mère, `override` dans les filles : la méthode est choisie d'après l'objet réel.
- `= 0` → méthode pure → classe abstraite, non instanciable.
- **Destructeur virtuel** dès qu'il y a une méthode virtuelle.
- `std::vector<std::unique_ptr<Base>>` pour une collection d'objets de types différents.
- Nouveau type = nouvelle classe, sans modifier le code existant.
- Méthode modèle : algorithme non virtuel + petites méthodes virtuelles.
