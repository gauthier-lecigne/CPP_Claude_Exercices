# 08 — Références et pointeurs

C'est **le** chapitre clé avant la POO. Tu as déjà croisé `&` et `*` dans le code
des trains (`Station*`, `const std::string&`) : voici ce qu'ils signifient.

## L'idée : chaque variable a une adresse

```
   Mémoire
   adresse      valeur
   0x7ffd10  │   42   │  <- int n = 42;
```

Une variable occupe une case en mémoire, repérée par une **adresse**.

## 1. Les références (`&` dans un type)

Une référence est un **deuxième nom** pour une variable existante.

```cpp
int n = 42;
int& r = n;     // r EST n (même case mémoire)

r = 100;
std::cout << n; // 100 : modifier r, c'est modifier n
```

Règles :
- une référence doit être initialisée à sa création (`int& r;` ne compile pas) ;
- elle ne peut jamais être « redirigée » vers une autre variable ;
- elle ne peut pas être « vide ».

### À quoi ça sert : le passage par référence

```cpp
void doubler(int& x) {   // x est un autre nom pour la variable passée
    x = x * 2;
}

int main() {
    int a = 5;
    doubler(a);
    std::cout << a;      // 10 : la variable d'origine a été modifiée
}
```

Compare avec le passage par valeur du chapitre 05, où la fonction ne modifiait qu'une copie.

### La référence constante : lire sans copier

```cpp
void afficher(const std::string& texte) {
    std::cout << texte;  // lecture OK
    // texte = "x";      // ERREUR : const interdit la modification
}
```

C'est la manière standard de passer un objet « gros » (string, vector, objet d'une classe) à une fonction qui ne fait que le lire.

| Paramètre | La fonction reçoit | Peut modifier l'original ? | Quand l'utiliser |
|---|---|---|---|
| `int x` | une copie | non | types simples (`int`, `double`, `char`, `bool`) |
| `int& x` | l'original | **oui** | la fonction doit modifier la variable |
| `const std::string& x` | l'original | non | gros objets en lecture seule |

## 2. Les pointeurs (`*` dans un type)

Un pointeur est une variable qui **contient une adresse**.

```cpp
int n = 42;
int* p = &n;      // &n = "l'adresse de n" ; p pointe vers n

std::cout << p;   // affiche une adresse, ex. 0x7ffd10
std::cout << *p;  // 42 : *p = "la valeur à l'adresse contenue dans p"

*p = 100;         // modifie n via le pointeur
std::cout << n;   // 100
```

⚠️ Les symboles changent de sens selon l'endroit :

| Où | `&` signifie | `*` signifie |
|---|---|---|
| Dans une **déclaration** de type | référence (`int& r`) | pointeur (`int* p`) |
| Devant une **variable** | adresse de (`&n`) | valeur pointée (`*p`) |

### `nullptr` : le pointeur qui ne pointe sur rien

Contrairement à une référence, un pointeur peut être vide :

```cpp
int* p = nullptr;

if (p != nullptr) {      // TOUJOURS vérifier avant de déréférencer
    std::cout << *p;
}
```

Déréférencer un `nullptr` fait planter le programme (*segmentation fault*).

C'est pour ça que `getNextStop()` renvoyait un `Station*` : quand le train est arrivé, il n'y a pas de prochaine gare, on renvoie `nullptr`.

### L'opérateur `->`

Avec un pointeur vers un objet (struct ou classe), `p->membre` est un raccourci pour `(*p).membre` :

```cpp
Station* s = &lyon;
s->getName();      // identique à (*s).getName()
```

### Pointeurs et tableaux

Un pointeur peut aussi désigner un élément d'un tableau, et on peut lui ajouter un entier pour avancer :

```cpp
int t[3] = {10, 20, 30};
int* p = t;          // pointe sur t[0]
std::cout << *(p + 1); // 20
```

Tu n'en auras pas souvent besoin avec `std::vector`, mais tu le croiseras dans du code C.

## 3. Allocation dynamique : `new` / `delete` et les pointeurs intelligents

Les variables « normales » sont détruites automatiquement à la fin de leur bloc.
Pour créer un objet qui **survit** au bloc, on l'alloue sur le *tas* :

```cpp
int* p = new int(42);   // crée un int sur le tas
std::cout << *p;
delete p;               // OBLIGATOIRE, sinon fuite de mémoire
p = nullptr;
```

Oublier `delete` = fuite mémoire. Faire `delete` deux fois = plantage. C'est source d'innombrables bugs.

**En C++ moderne, on n'écrit quasiment jamais `new`/`delete` à la main.** On utilise `std::unique_ptr` (`#include <memory>`), qui libère tout seul :

```cpp
#include <memory>

std::unique_ptr<int> p = std::make_unique<int>(42);
std::cout << *p;
// pas de delete : la mémoire est libérée automatiquement à la fin du bloc
```

Tu en auras besoin au chapitre 15 pour le polymorphisme (le `vector<unique_ptr<Train>>` du projet ferroviaire).

## Référence ou pointeur ?

| Besoin | Choix |
|---|---|
| Paramètre qu'une fonction modifie | `T&` |
| Paramètre lu sans copie | `const T&` |
| Quelque chose qui peut être « absent » | `T*` (avec `nullptr`) |
| Pointer vers un objet qu'on ne possède pas (une gare sur une ligne) | `T*` |
| Posséder un objet alloué dynamiquement | `std::unique_ptr<T>` |

## À retenir

- `T&` = un autre nom pour une variable ; sert surtout au passage de paramètres.
- `T*` = une adresse ; `&x` prend l'adresse, `*p` lit la valeur, `p->m` accède à un membre.
- Toujours tester un pointeur contre `nullptr` avant de l'utiliser.
- Pas de `new`/`delete` à la main : `std::unique_ptr` et `std::make_unique`.
