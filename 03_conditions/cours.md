# 03 — Conditions

## `if` / `else if` / `else`

```cpp
int note = 14;

if (note >= 16) {
    std::cout << "Tres bien\n";
} else if (note >= 10) {
    std::cout << "Admis\n";
} else {
    std::cout << "Ajourne\n";
}
```

Les conditions sont testées **dans l'ordre** : dès qu'une est vraie, les suivantes sont ignorées.
Ici, `note >= 10` n'est testé que si `note >= 16` est faux.

## Opérateurs de comparaison

| Opérateur | Sens |
|---|---|
| `==` | égal à |
| `!=` | différent de |
| `<`, `<=` | inférieur (ou égal) |
| `>`, `>=` | supérieur (ou égal) |

⚠️ **Le piège classique** : `=` affecte, `==` compare.

```cpp
if (x = 5)   // affecte 5 à x, et 5 est "vrai" : toujours exécuté !
if (x == 5)  // compare : c'est ce qu'on veut
```

Avec `-Wall`, le compilateur t'avertit. Encore une raison de garder les warnings.

## Opérateurs logiques

| Opérateur | Sens | Exemple |
|---|---|---|
| `&&` | ET : les deux doivent être vrais | `age >= 18 && age < 65` |
| `\|\|` | OU : au moins un vrai | `jour == 6 \|\| jour == 7` |
| `!` | NON | `!estMajeur` |

⚠️ On ne peut pas écrire `0 <= x <= 20` comme en maths. Il faut `x >= 0 && x <= 20`.

## Les booléens

Une condition est une valeur `bool`. On peut la stocker :

```cpp
bool estPair = (n % 2 == 0);
if (estPair) { ... }       // et non if (estPair == true)
```

## `switch` : choisir parmi des valeurs précises

```cpp
char op = '+';

switch (op) {
    case '+':
        std::cout << a + b;
        break;              // sans break, on continue dans le case suivant !
    case '-':
        std::cout << a - b;
        break;
    default:                // aucun case ne correspond
        std::cout << "Operateur inconnu";
}
```

`switch` ne marche qu'avec des entiers et des `char` (pas avec des `string` ni des `double`).

## L'opérateur ternaire

Un `if/else` compact qui **produit une valeur** :

```cpp
std::string etat = (age >= 18) ? "majeur" : "mineur";
int max = (a > b) ? a : b;
```

À réserver aux cas très simples ; sinon un `if` est plus lisible.

## Toujours mettre des accolades

```cpp
if (x > 0)
    std::cout << "positif\n";
    std::cout << "toujours affiche !\n";   // n'est PAS dans le if, malgré l'indentation
```

Mets des `{ }` même pour une seule ligne : tu éviteras ce bug.

## À retenir

- `==` pour comparer, `=` pour affecter.
- `&&`, `||`, `!` pour combiner.
- Les `else if` sont testés dans l'ordre.
- `break` à la fin de chaque `case`.
