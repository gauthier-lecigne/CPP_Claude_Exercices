# 13 — Composition et agrégation : des objets dans des objets

Les vrais programmes ne sont pas faits d'une classe isolée, mais de classes qui
**se contiennent** ou **se connaissent**. C'est ce que représentent les losanges
de ton diagramme UML.

## Les trois relations « a un »

| Relation | UML | Sens | En C++ | Exemple |
|---|---|---|---|---|
| **Composition** | ◆── (losange plein) | A **possède** B. B naît et meurt avec A. | attribut par valeur `B b;`, `std::vector<B>`, `std::unique_ptr<B>` | Une `Ligne` possède ses `Segment` |
| **Agrégation** | ◇── (losange vide) | A **utilise** des B qui existent indépendamment. | pointeur ou référence `B*`, `std::vector<B*>` | Une `Ligne` dessert des `Gare` |
| **Association** | ── (trait / flèche) | A connaît B, sans notion de « tout / partie ». | pointeur `B*` | Un `Train` circule sur une `Ligne` |

La question à se poser : **« Si je détruis A, est-ce que B doit disparaître ? »**
- Oui → composition (A est propriétaire).
- Non, B sert ailleurs → agrégation ou association (A ne fait que pointer).

> Si on supprime la ligne A, la gare de Lyon Part-Dieu doit continuer d'exister pour les autres lignes : c'est une agrégation.

## Composition : l'objet est un attribut

```cpp
class Moteur {
public:
    explicit Moteur(int puissance) : puissance(puissance) {}
    int getPuissance() const { return puissance; }
private:
    int puissance;
};

class Voiture {
public:
    Voiture(const std::string& modele, int puissance)
        : modele(modele), moteur(puissance) {}   // on construit le moteur ici

    void afficher() const {
        std::cout << modele << " (" << moteur.getPuissance() << " ch)\n";
    }
private:
    std::string modele;
    Moteur moteur;     // la voiture CONTIENT un moteur
};
```

- `Moteur` n'a pas de constructeur par défaut : la **liste d'initialisation est obligatoire** pour construire l'attribut `moteur`.
- Détruire la `Voiture` détruit automatiquement son `Moteur`.
- `Voiture` utilise l'**interface publique** de `Moteur` (`getPuissance()`), pas ses attributs privés. Chaque classe garde ses secrets.

Composition de **plusieurs** objets :

```cpp
class Bibliotheque {
private:
    std::vector<Livre> livres;   // la bibliothèque possède ses livres
};
```

## Agrégation : un pointeur vers un objet qui vit ailleurs

```cpp
class Ligne {
public:
    explicit Ligne(const std::string& nom) : nom(nom) {}

    void ajouterGare(const Gare* g) {
        if (g != nullptr) {
            gares.push_back(g);
        }
    }

private:
    std::string nom;
    std::vector<const Gare*> gares;   // la ligne CONNAÎT des gares, elle ne les possède pas
};
```

- `const Gare*` : la ligne peut lire les gares mais pas les modifier.
- La ligne ne fait **jamais** `delete` sur ces gares : ce n'est pas elle qui les a créées.
- ⚠️ Danger : si la gare est détruite alors que la ligne pointe encore dessus, le pointeur devient **pendant** (*dangling*). Il faut que le propriétaire des gares vive **plus longtemps** que les lignes.

## Qui possède quoi ? Un propriétaire central

Solution classique : un objet central possède tout, les autres pointent.

```cpp
class Reseau {
private:
    std::vector<std::unique_ptr<Gare>> gares;  // composition : le réseau possède les gares
    std::vector<Ligne> lignes;                 // composition : et les lignes
};                                             // chaque Ligne pointe vers des gares du réseau
```

### Pourquoi `unique_ptr<Gare>` et pas `vector<Gare>` ?

```cpp
std::vector<Gare> gares;
gares.push_back(Gare("Lyon", 4));
Gare* lyon = &gares[0];
gares.push_back(Gare("Macon", 2));   // le vector peut se réallouer ailleurs en mémoire...
lyon->getNom();                       // ... et lyon pointe maintenant dans le vide !
```

Quand un `vector` grandit, il peut **déplacer** tous ses éléments : les pointeurs vers ces éléments deviennent invalides.
Avec `std::vector<std::unique_ptr<Gare>>`, chaque `Gare` est allouée à part et **ne bouge jamais** : seuls les `unique_ptr` sont déplacés. Les `Gare*` restent valides.

## Exposer ce qu'on contient

Pour laisser l'extérieur **lire** une collection sans pouvoir la modifier ni la copier :

```cpp
const std::vector<const Gare*>& getGares() const { return gares; }
```

Pour trouver un élément, renvoie un pointeur (`nullptr` si absent) :

```cpp
const Gare* Reseau::trouverGare(const std::string& nom) const {
    for (const auto& g : gares) {
        if (g->getNom() == nom) {
            return g.get();
        }
    }
    return nullptr;
}
```

## Déclaration anticipée (*forward declaration*)

Si `Ligne.hpp` ne manipule que des **pointeurs** vers `Gare`, il n'a pas besoin de connaître toute la classe :

```cpp
// Ligne.hpp
class Gare;   // "une classe Gare existe", ça suffit pour déclarer un Gare*

class Ligne {
    std::vector<const Gare*> gares;
};
```

Le `#include "Gare.hpp"` complet ne va que dans `Ligne.cpp`, là où l'on appelle `g->getNom()`.
Avantages : compilation plus rapide, et c'est la solution quand deux classes se référencent **mutuellement** (sinon les `#include` tournent en rond).

## À retenir

- Composition (◆) : attribut par valeur, `vector<T>` ou `unique_ptr<T>` ; détruit avec le propriétaire.
- Agrégation (◇) / association : `T*` ; ne jamais `delete` ce qu'on ne possède pas.
- Un propriétaire central qui vit plus longtemps que ceux qui pointent.
- Ne garde pas de pointeurs vers les éléments d'un `vector<T>` qui grandit : utilise `vector<unique_ptr<T>>`.
- `class Gare;` dans un `.hpp` quand on n'a besoin que de pointeurs.
