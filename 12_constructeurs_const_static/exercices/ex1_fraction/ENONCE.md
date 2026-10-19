# Exercice 1 — La classe `Fraction`

Écris une classe `Fraction` (fichiers `src/Fraction.hpp` et `src/Fraction.cpp`)
qui représente une fraction **toujours simplifiée**.

## Invariants

À tout moment :
1. le dénominateur est **strictement positif** (le signe est porté par le numérateur : `-1/2`, jamais `1/-2`) ;
2. la fraction est **irréductible** : `2/4` est stockée comme `1/2` ;
3. zéro s'écrit `0/1`.

Ces règles sont garanties par une méthode **privée** `void simplifier();` appelée à la fin du constructeur. Comme les autres opérations créent de nouvelles fractions via le constructeur, elles en profitent automatiquement.

Si le dénominateur passé vaut `0`, utilise `1` à la place (on verra les exceptions plus tard).

## Interface

| Méthode | Exemple |
|---|---|
| `Fraction(int numerateur = 0, int denominateur = 1)` | `Fraction(6, -8)` → `-3/4` |
| `int getNumerateur() const` / `int getDenominateur() const` | |
| `Fraction additionner(const Fraction& autre) const` | `1/2 + 1/3 = 5/6` |
| `Fraction multiplier(const Fraction& autre) const` | `2/3 × 3/4 = 1/2` |
| `Fraction inverse() const` | `inverse(-3/4) = -4/3` |
| `bool egale(const Fraction& autre) const` | `1/2` égale `2/4` |
| `double versDouble() const` | `3/4` → `0.75` |
| `std::string toString() const` | `"5/6"`, et `"3"` quand le dénominateur vaut 1 |

Utilise une **liste d'initialisation** dans le constructeur. Pour simplifier, il faut le PGCD : `std::gcd` de `<numeric>` le calcule, ou réutilise l'algorithme d'Euclide du chapitre 05 dans une fonction `static` privée.

## Bonus : opérateurs

Ajoute `operator+`, `operator*`, `operator==` (en réutilisant tes méthodes) et la fonction libre
`std::ostream& operator<<(std::ostream& out, const Fraction& f);` pour pouvoir écrire :

```cpp
std::cout << (a + b) * c << std::endl;
```

Pour activer les tests du bonus, décommente la ligne `#define BONUS_OPERATEURS` en haut de `main.cpp`.

## Résultat attendu

```
12/12 tests reussis          (14/14 avec le bonus)
```
