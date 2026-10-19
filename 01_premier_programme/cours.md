# 01 — Premier programme

## La structure d'un programme

```cpp
#include <iostream>   // (1) on importe la bibliothèque d'entrées/sorties

int main() {          // (2) point d'entrée : le programme commence ici
    std::cout << "Bonjour !" << std::endl;   // (3) une instruction
    return 0;         // (4) 0 = "tout s'est bien passé"
}
```

1. `#include` copie le contenu d'une bibliothèque dans ton fichier. `<iostream>` fournit `std::cout` et `std::cin`.
2. Tout programme C++ a **exactement une** fonction `main`. C'est là que l'exécution démarre.
3. Chaque instruction se termine par un **point-virgule** `;`.
4. `return 0;` à la fin de `main` est facultatif (le compilateur l'ajoute), mais c'est une bonne habitude.

## Afficher : `std::cout`

```cpp
std::cout << "Age : " << 21 << " ans" << std::endl;
```

- `<<` « envoie » ce qui est à droite vers la console. On peut enchaîner autant de `<<` qu'on veut.
- `std::endl` passe à la ligne. On peut aussi écrire `"\n"` dans une chaîne :

```cpp
std::cout << "Ligne 1\nLigne 2\n";
```

Caractères spéciaux utiles : `\n` (nouvelle ligne), `\t` (tabulation), `\"` (guillemet), `\\` (antislash).

## Lire : `std::cin`

```cpp
int age;
std::cout << "Quel age as-tu ? ";
std::cin >> age;
std::cout << "Dans 10 ans tu auras " << age + 10 << " ans." << std::endl;
```

- `>>` lit une valeur tapée au clavier et la range dans la variable.
- On peut lire plusieurs valeurs d'un coup : `std::cin >> a >> b;` (l'utilisateur les sépare par un espace ou Entrée).
- `std::cin >> unString;` ne lit **qu'un mot** (il s'arrête à l'espace). Pour une ligne entière, on verra `getline` au chapitre 07.

## `std::` et `using namespace std;`

`std` est l'**espace de noms** de la bibliothèque standard. On écrit `std::cout` pour dire « le `cout` de la bibliothèque standard ».

Tu verras souvent :

```cpp
using namespace std;   // permet d'écrire cout au lieu de std::cout
```

C'est pratique dans un petit exercice, mais **à éviter dans un `.hpp`** (ça « pollue » tous les fichiers qui l'incluent). Dans ce cours on écrit `std::` partout pour prendre la bonne habitude.

## Les commentaires

```cpp
// Commentaire sur une ligne

/* Commentaire
   sur plusieurs lignes */
```

Un bon commentaire explique **pourquoi**, pas **quoi** : `i++; // incrémente i` est inutile.

## À retenir

- Un programme = `#include` + `int main() { ... }`.
- `;` à la fin de chaque instruction.
- `std::cout <<` pour afficher, `std::cin >>` pour lire.
- Toujours recompiler après une modification.
