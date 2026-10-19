# 05 — Fonctions

Une fonction est un bloc de code **nommé et réutilisable**. Elle prend des entrées
(les *paramètres*) et peut produire une sortie (la *valeur de retour*).

## Anatomie

```cpp
//  type de retour   nom      paramètres
       double      moyenne(double a, double b) {
           return (a + b) / 2;      // renvoie le résultat et QUITTE la fonction
       }

int main() {
    double m = moyenne(12, 15);     // appel : m vaut 13.5
    std::cout << moyenne(8, 10);    // affiche 9
}
```

- Le **type de retour** dit ce que la fonction renvoie (`int`, `double`, `bool`, `std::string`…).
- `void` signifie « ne renvoie rien » :

```cpp
void afficherLigne(int longueur) {
    for (int i = 0; i < longueur; i++) {
        std::cout << "-";
    }
    std::cout << "\n";
}   // pas de return obligatoire
```

## Pourquoi écrire des fonctions ?

1. **Ne pas se répéter** : un calcul écrit une fois, utilisé partout.
2. **Lisibilité** : `if (estPremier(n))` se lit comme une phrase.
3. **Tester** facilement un morceau isolé.
4. C'est la base de la POO : les **méthodes** d'une classe sont des fonctions.

Règle pratique : une fonction fait **une seule chose**, et son nom le dit.

## L'ordre compte : les prototypes

Le compilateur lit le fichier **de haut en bas**. Une fonction doit être connue avant d'être appelée.

```cpp
int carre(int x);          // prototype (déclaration) : "cette fonction existe"

int main() {
    std::cout << carre(4); // OK grâce au prototype
}

int carre(int x) {         // définition : le vrai code
    return x * x;
}
```

C'est **exactement** le principe des fichiers `.hpp` (prototypes) et `.cpp` (définitions) que tu verras en POO.

## Le passage par valeur

Par défaut, une fonction reçoit une **copie** de l'argument :

```cpp
void tenterDeModifier(int x) {
    x = 100;               // modifie la copie seulement
}

int main() {
    int n = 5;
    tenterDeModifier(n);
    std::cout << n;        // affiche toujours 5
}
```

Pour modifier la variable d'origine, il faut un **passage par référence** (`int& x`), vu au chapitre 08.

## La portée des variables

Une variable n'existe que dans le bloc `{ }` où elle est déclarée.

```cpp
void f() {
    int local = 3;
}

int main() {
    f();
    std::cout << local;    // ERREUR : local n'existe pas ici
}
```

Évite les variables **globales** (déclarées hors de toute fonction) : n'importe quelle fonction peut les modifier, ce qui rend les bugs très difficiles à trouver. Passe plutôt les valeurs en paramètres.

## Paramètres par défaut

```cpp
void saluer(std::string nom, std::string formule = "Bonjour") {
    std::cout << formule << " " << nom << "\n";
}

saluer("Gauthier");            // Bonjour Gauthier
saluer("Gauthier", "Salut");   // Salut Gauthier
```

Les paramètres par défaut doivent être **à la fin** de la liste.

## La surcharge

Plusieurs fonctions peuvent porter le même nom si leurs paramètres diffèrent :

```cpp
int    maximum(int a, int b)          { return a > b ? a : b; }
double maximum(double a, double b)    { return a > b ? a : b; }
int    maximum(int a, int b, int c)   { return maximum(maximum(a, b), c); }
```

Le compilateur choisit la bonne version selon les arguments.

## La récursivité

Une fonction peut s'appeler elle-même. Il faut **toujours** un cas d'arrêt :

```cpp
int factorielle(int n) {
    if (n <= 1) {
        return 1;                     // cas d'arrêt
    }
    return n * factorielle(n - 1);    // appel récursif sur un problème plus petit
}
```

```
factorielle(4) = 4 * factorielle(3)
               = 4 * 3 * factorielle(2)
               = 4 * 3 * 2 * factorielle(1)
               = 4 * 3 * 2 * 1 = 24
```

Sans cas d'arrêt, la fonction s'appelle à l'infini et le programme plante (*stack overflow*).

## À retenir

- Une fonction = type de retour + nom + paramètres + corps.
- `return` renvoie une valeur **et** termine la fonction.
- Les arguments sont **copiés** par défaut.
- Prototype en haut, définition en bas : c'est l'idée des `.hpp` / `.cpp`.
