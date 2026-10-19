# 04 — Boucles

Une boucle répète un bloc d'instructions. Il en existe trois, chacune adaptée à une situation.

## `for` : quand on sait combien de fois

```cpp
for (int i = 0; i < 5; i++) {
    std::cout << i << " ";
}
// affiche : 0 1 2 3 4
```

Les trois parties entre parenthèses :

```
for ( initialisation ; condition ; mise à jour )
       int i = 0        i < 5       i++
       (une fois)     (avant chaque tour)  (après chaque tour)
```

Variantes courantes :

```cpp
for (int i = 1; i <= 10; i++)    // de 1 à 10 inclus
for (int i = 10; i > 0; i--)     // compte à rebours
for (int i = 0; i < 100; i += 5) // de 5 en 5
```

⚠️ `i` n'existe que **dans** la boucle. Après l'accolade fermante, il a disparu.

## `while` : tant qu'une condition est vraie

```cpp
int n = 1;
while (n < 1000) {
    n = n * 2;
}
std::cout << n;   // 1024
```

On l'utilise quand on **ne sait pas à l'avance** combien de tours il faudra.

⚠️ Si la condition ne devient jamais fausse, c'est une **boucle infinie** : le programme ne s'arrête plus. Dans le terminal, `Ctrl+C` le stoppe.

## `do … while` : au moins une fois

```cpp
int choix;
do {
    std::cout << "Entre un nombre entre 1 et 3 : ";
    std::cin >> choix;
} while (choix < 1 || choix > 3);
```

Le bloc est exécuté **avant** de tester la condition. Idéal pour **valider une saisie** : on redemande tant que la réponse est mauvaise.
N'oublie pas le `;` après le `while (...)`.

## `break` et `continue`

```cpp
for (int i = 1; i <= 10; i++) {
    if (i == 3) continue;   // saute la suite de CE tour, passe à i = 4
    if (i == 6) break;      // sort complètement de la boucle
    std::cout << i << " ";
}
// affiche : 1 2 4 5
```

## Boucles imbriquées

```cpp
for (int ligne = 1; ligne <= 3; ligne++) {
    for (int col = 1; col <= 4; col++) {
        std::cout << "*";
    }
    std::cout << "\n";
}
```

```
****
****
****
```

La boucle intérieure fait **tous** ses tours à chaque tour de la boucle extérieure.

## Accumuler un résultat

Motif très fréquent : une variable déclarée **avant** la boucle, mise à jour **dedans**.

```cpp
int somme = 0;               // initialisée avant !
for (int i = 1; i <= 100; i++) {
    somme += i;
}
std::cout << somme;          // 5050
```

## Quelle boucle choisir ?

| Situation | Boucle |
|---|---|
| Nombre de tours connu | `for` |
| On s'arrête sur une condition | `while` |
| Il faut faire le bloc au moins une fois (saisie) | `do … while` |

## À retenir

- `for` pour compter, `while` pour attendre une condition, `do…while` pour valider une saisie.
- Les accumulateurs s'initialisent **avant** la boucle.
- Vérifie toujours que la boucle se termine.
