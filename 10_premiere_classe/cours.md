# 10 — Première classe

## Le problème avec les struct

```cpp
struct Compte {
    std::string titulaire;
    double solde;
};

Compte c{"Gauthier", 100};
c.solde = -5000;     // rien ne l'empêche !
```

Avec une `struct`, n'importe quel code peut mettre les données dans un état absurde.
Une **classe** règle ce problème : elle **protège** ses données et fournit des
**méthodes** (des fonctions attachées à l'objet) qui sont les seules à pouvoir les modifier.

## Vocabulaire

| Terme | Signification | Exemple |
|---|---|---|
| **Classe** | Le modèle, le « plan » | `class Compte { ... };` |
| **Objet** / instance | Une variable créée à partir de la classe | `Compte c("Gauthier");` |
| **Attribut** | Une donnée de l'objet | `solde` |
| **Méthode** | Une fonction de l'objet | `deposer(50)` |
| **Encapsulation** | Cacher les données, n'exposer que des méthodes | `private` / `public` |

Une classe = un plan de maison ; un objet = une maison construite d'après ce plan.
On peut construire autant de maisons qu'on veut, chacune avec ses propres valeurs.

## Une première classe

```cpp
class Compte {
public:                                  // accessible depuis l'extérieur
    Compte(const std::string& titulaire) {   // constructeur
        this->titulaire = titulaire;
        solde = 0.0;
    }

    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
        }
    }

    bool retirer(double montant) {
        if (montant <= 0 || montant > solde) {
            return false;                // refusé : la règle est garantie
        }
        solde -= montant;
        return true;
    }

    double getSolde() const {            // const : ne modifie pas l'objet
        return solde;
    }

private:                                 // accessible SEULEMENT par les méthodes de Compte
    std::string titulaire;
    double solde;
};   // ⚠️ point-virgule
```

Utilisation :

```cpp
int main() {
    Compte c("Gauthier");      // appelle le constructeur
    c.deposer(100);
    c.retirer(30);
    std::cout << c.getSolde(); // 70

    c.solde = -5000;           // ERREUR de compilation : solde est private
}
```

**L'intérêt** : il est désormais **impossible** d'avoir un solde négatif, car le seul moyen de toucher au solde passe par `deposer` et `retirer`, qui vérifient les règles. Ces règles toujours vraies s'appellent des **invariants**.

## `public` et `private`

| Mot-clé | Qui peut y accéder |
|---|---|
| `public:` | tout le monde |
| `private:` | uniquement les méthodes de la classe |

Règle par défaut : **attributs `private`, méthodes `public`** (sauf les méthodes utilitaires internes, en `private` aussi).

## Le constructeur

Une méthode spéciale :
- elle porte **le nom de la classe** ;
- elle n'a **pas de type de retour** (même pas `void`) ;
- elle est appelée **automatiquement** à la création de l'objet.

Son rôle : mettre l'objet dans un état valide dès sa naissance.
On verra au chapitre 12 la forme recommandée (*liste d'initialisation*).

## `this`

Dans une méthode, `this` est un **pointeur vers l'objet courant**.
On l'utilise surtout quand un paramètre a le même nom qu'un attribut :

```cpp
Compte(const std::string& titulaire) {
    this->titulaire = titulaire;   // attribut = paramètre
}
```

Sans `this->`, `titulaire = titulaire;` affecterait le paramètre à lui-même.

## Getters et setters

```cpp
double getSolde() const { return solde; }        // getter : lire
void setTaux(double t) {                          // setter : écrire avec contrôle
    if (t >= 0 && t <= 0.1) {
        taux = t;
    }
}
```

⚠️ Ne crée pas un getter **et** un setter pour chaque attribut par réflexe : un setter sans contrôle revient à rendre l'attribut public. Demande-toi plutôt **quelles actions** ont du sens (`deposer`, pas `setSolde`).

## Les méthodes `const`

```cpp
double getSolde() const;
```

Le `const` après les parenthèses promet que la méthode **ne modifie pas** l'objet.
C'est indispensable : une méthode non `const` ne peut pas être appelée sur un objet `const`
(par exemple un paramètre `const Compte&`).

**Réflexe** : toute méthode qui ne fait que lire (getters, affichage, calculs) doit être `const`.

## Plusieurs objets, chacun ses données

```cpp
Compte a("Gauthier");
Compte b("Lea");
a.deposer(100);
b.deposer(20);
// a.getSolde() == 100, b.getSolde() == 20 : chaque objet a SES attributs
```

## À retenir

- Une classe regroupe des **données privées** et des **méthodes publiques**.
- Le constructeur initialise l'objet dans un état valide.
- Les méthodes garantissent les **invariants** (ex. : solde jamais négatif).
- `const` sur toute méthode qui ne modifie pas l'objet.
- Dans ce chapitre tout est dans un seul fichier ; au chapitre 11 on sépare en `.hpp` / `.cpp`.
