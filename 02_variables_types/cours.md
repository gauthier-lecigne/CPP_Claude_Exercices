# 02 — Variables et types

Une variable est une **boîte nommée** qui contient une valeur d'un **type** précis.
En C++, le type est fixé une fois pour toutes : une variable `int` ne contiendra jamais de texte.

```cpp
int age = 21;          // déclaration + initialisation
age = 22;              // modification
```

## Les types de base

| Type | Contient | Exemple |
|---|---|---|
| `int` | Entier (environ ±2 milliards) | `int n = -42;` |
| `long long` | Grand entier | `long long pop = 8000000000LL;` |
| `double` | Nombre à virgule | `double prix = 19.99;` |
| `char` | **Un** caractère, entre apostrophes | `char lettre = 'A';` |
| `bool` | `true` ou `false` | `bool majeur = true;` |
| `std::string` | Du texte, entre guillemets (`#include <string>`) | `std::string nom = "Lyon";` |

⚠️ `'A'` (apostrophes) est un `char`, `"A"` (guillemets) est une chaîne.

⚠️ Une variable non initialisée contient **n'importe quoi** :

```cpp
int x;            // valeur imprévisible !
std::cout << x;   // affiche peut-être 32765
int y = 0;        // toujours initialiser
```

## Les opérateurs

`+  -  *  /  %` (le `%` est le **reste** de la division entière : `17 % 5 == 2`).

Raccourcis : `x += 3;` (= `x = x + 3`), `x++;` (= `x = x + 1`), `x--;`.

### Le piège n°1 : la division entière

```cpp
int a = 7, b = 2;
std::cout << a / b;        // affiche 3, pas 3.5 !
```

Entre deux `int`, `/` donne un `int` (on tronque). Pour avoir 3.5, il faut qu'**au moins un** des deux soit un `double` :

```cpp
std::cout << static_cast<double>(a) / b;   // 3.5
std::cout << 7.0 / 2;                      // 3.5
```

Le même piège frappe les moyennes : `(12 + 15 + 14) / 3` vaut `13`, pas `13.666...`.

## Les conversions

```cpp
double d = 3.9;
int i = static_cast<int>(d);     // 3 (tronqué, pas arrondi)

int n = 65;
char c = static_cast<char>(n);   // 'A' (code ASCII 65)
```

`static_cast<Type>(valeur)` est la façon propre et explicite de convertir en C++.
Tu verras aussi `(int)d` (style C) : ça marche, mais c'est moins lisible et moins sûr.

## `const` : une valeur qui ne change pas

```cpp
const double TVA = 0.20;
TVA = 0.10;   // ERREUR de compilation
```

Utilise `const` dès qu'une valeur ne doit pas changer. C'est une protection gratuite.

## `auto` : laisser le compilateur deviner

```cpp
auto x = 42;      // int
auto y = 3.14;    // double
auto z = 'k';     // char
```

Pratique avec des types longs (on le verra avec les `vector`), mais pour les types simples,
écrire `int` ou `double` est plus clair.

## Lire plusieurs types

```cpp
std::string nom;
int age;
double taille;
std::cin >> nom >> age >> taille;   // l'utilisateur tape : Gauthier 21 1.80
```

⚠️ Le séparateur décimal est le **point** : `1.80`, pas `1,80`.

## À retenir

- Toujours initialiser ses variables.
- `int / int` donne un `int` : utilise `static_cast<double>` pour une vraie division.
- `%` donne le reste, très utile (pair/impair, conversions d'unités…).
- `const` pour les valeurs fixes.
