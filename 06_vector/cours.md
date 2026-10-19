# 06 — Tableaux et `std::vector`

Pour stocker **plusieurs valeurs du même type**, on utilise un tableau.
En C++ moderne, l'outil par défaut est `std::vector` (`#include <vector>`).

## Créer un vector

```cpp
#include <vector>

std::vector<int> notes;                    // vide
std::vector<int> premiers = {2, 3, 5, 7};  // avec des valeurs
std::vector<double> zeros(5, 0.0);         // 5 cases valant 0.0
std::vector<std::string> villes = {"Lyon", "Macon", "Dijon"};
```

Le type entre `< >` est le type des éléments.

## Les opérations essentielles

```cpp
std::vector<int> v = {10, 20, 30};

v.push_back(40);         // ajoute à la fin       -> {10, 20, 30, 40}
v.pop_back();            // retire le dernier     -> {10, 20, 30}
v.size();                // nombre d'éléments     -> 3
v.empty();               // true si vide
v[0];                    // premier élément       -> 10
v[v.size() - 1];         // dernier élément       -> 30
v.back();                // dernier élément aussi
v[1] = 25;               // modification          -> {10, 25, 30}
v.clear();               // vide tout
```

⚠️ Les indices commencent à **0**. Un vector de taille 3 a les indices 0, 1, 2.
Accéder à `v[3]` est un **comportement indéfini** : le programme peut afficher n'importe quoi ou planter, sans message clair.
`v.at(3)` vérifie l'indice et lève une erreur explicite : pratique pour déboguer.

## Parcourir un vector

**Avec un indice** (quand on a besoin de la position) :

```cpp
for (std::size_t i = 0; i < v.size(); i++) {
    std::cout << "Case " << i << " : " << v[i] << "\n";
}
```

`v.size()` renvoie un `std::size_t` (entier **non signé**). Utiliser `std::size_t` pour `i` évite un warning de comparaison signé/non signé.

**Avec un range-for** (quand on veut juste chaque valeur) :

```cpp
for (int x : v) {
    std::cout << x << " ";
}
```

Se lit : « pour chaque `x` dans `v` ». `x` est une **copie** : la modifier ne change pas le vector.

Pour modifier les éléments, on utilise une **référence** (`&`, détaillé au chapitre 08) :

```cpp
for (int& x : v) {
    x = x * 2;      // modifie vraiment le vector
}
```

## Passer un vector à une fonction

```cpp
double moyenne(const std::vector<double>& valeurs) {
    double somme = 0;
    for (double x : valeurs) {
        somme += x;
    }
    return somme / valeurs.size();
}
```

- `&` : on passe une **référence** au lieu d'une copie. Copier un vector de 1 million d'éléments serait très lent.
- `const` : la fonction promet de ne pas le modifier.

**Règle** : pour un vector (ou une `string`) en paramètre, écris `const std::vector<T>&` si tu le lis seulement, `std::vector<T>&` si tu le modifies.

## Les tableaux « à la C »

Tu en croiseras dans du code ancien :

```cpp
int t[5] = {1, 2, 3, 4, 5};   // taille fixe, ne connaît pas sa propre taille
```

Ils n'ont pas de `size()`, pas de `push_back`, et passent mal en paramètre. Préfère `std::vector`
(ou `std::array<int, 5>` si la taille est fixe et connue à la compilation).

## Quelques algorithmes utiles (`#include <algorithm>`)

```cpp
std::sort(v.begin(), v.end());                       // trie
auto it = std::max_element(v.begin(), v.end());      // itérateur vers le max
int m = *it;                                         // valeur du max
std::reverse(v.begin(), v.end());                    // inverse
int nb = std::count(v.begin(), v.end(), 3);          // nombre de 3
```

`v.begin()` et `v.end()` désignent le début et la fin du vector. Dans les exercices, on te demande d'abord de **réécrire** ces algorithmes à la main : c'est le meilleur moyen de comprendre les boucles.

## À retenir

- `std::vector<T>` : tableau dynamique, la taille s'adapte.
- Indices de `0` à `size() - 1`.
- `push_back` pour ajouter, `size()` pour la taille.
- Range-for pour lire, `for (T& x : v)` pour modifier.
- En paramètre : `const std::vector<T>&`.
