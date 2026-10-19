# 11 — Séparer une classe en `.hpp` et `.cpp`

Au chapitre 10, toute la classe tenait dans un seul fichier. Dans un vrai projet,
chaque classe est répartie dans **deux fichiers** :

| Fichier | Contient | Analogie |
|---|---|---|
| `Compte.hpp` (header) | La **déclaration** : attributs et prototypes des méthodes | Le sommaire / le mode d'emploi |
| `Compte.cpp` (source) | La **définition** : le code des méthodes | Le contenu des chapitres |

C'est exactement l'idée des prototypes du chapitre 05, appliquée aux classes.

## Pourquoi séparer ?

1. **Lisibilité** : le `.hpp` donne en un coup d'œil tout ce que la classe sait faire, sans le détail.
2. **Compilation plus rapide** : si tu modifies `Compte.cpp`, seul ce fichier est recompilé.
3. **Réutilisation** : n'importe quel fichier fait `#include "Compte.hpp"` pour utiliser la classe.
4. C'est **la norme** : c'est ce qu'on attend de toi à SUPINFO et en entreprise.

## Le fichier `.hpp`

```cpp
// Compte.hpp
#ifndef COMPTE_HPP          // (1) include guard
#define COMPTE_HPP

#include <string>           // (2) seulement ce dont la DÉCLARATION a besoin

class Compte {
public:
    Compte(const std::string& titulaire, double soldeInitial);

    void deposer(double montant);          // (3) prototypes seulement : pas de { }
    bool retirer(double montant);
    double getSolde() const;
    std::string getTitulaire() const;

private:
    std::string titulaire;
    double solde;
};

#endif                      // fin de l'include guard
```

1. **L'include guard** (`#ifndef / #define / #endif`) empêche le contenu d'être inclus deux fois dans le même fichier compilé. Sans lui : erreur `redefinition of 'class Compte'`. Le nom (`COMPTE_HPP`) doit être unique : on prend le nom du fichier en majuscules.
   Tu verras aussi `#pragma once` en première ligne, qui fait la même chose en plus court. Les deux sont acceptés.
2. N'inclus que le nécessaire. **Jamais de `using namespace std;` dans un `.hpp`** : tous les fichiers qui l'incluent en hériteraient.
3. Les méthodes sont seulement **déclarées** : nom, paramètres, type de retour, `const`, suivis d'un `;`.

## Le fichier `.cpp`

```cpp
// Compte.cpp
#include "Compte.hpp"       // (1) guillemets pour nos fichiers, chevrons pour la bibliothèque standard

#include <iostream>         // (2) ce dont seul le CODE a besoin

Compte::Compte(const std::string& titulaire, double soldeInitial) {   // (3)
    this->titulaire = titulaire;
    solde = (soldeInitial > 0) ? soldeInitial : 0.0;
}

void Compte::deposer(double montant) {
    if (montant > 0) {
        solde += montant;
    }
}

bool Compte::retirer(double montant) {
    if (montant <= 0 || montant > solde) {
        return false;
    }
    solde -= montant;
    return true;
}

double Compte::getSolde() const {          // (4) le const est répété
    return solde;
}

std::string Compte::getTitulaire() const {
    return titulaire;
}
```

1. `#include "Compte.hpp"` en **premier** : si le header oublie un `#include`, l'erreur apparaît tout de suite.
2. Les includes qui ne servent qu'à l'implémentation vont ici, pas dans le `.hpp`.
3. **`Compte::`** est l'opérateur de **résolution de portée** : il dit « cette fonction `deposer` est celle de la classe `Compte` ». Sans lui, tu définirais une fonction libre `deposer` sans rapport avec la classe, et le compilateur ne trouverait pas `solde`.
4. Le `const` doit apparaître dans le `.hpp` **et** dans le `.cpp`. Les valeurs par défaut des paramètres, elles, ne s'écrivent **que dans le `.hpp`**.

## Le `main.cpp`

```cpp
// main.cpp
#include <iostream>
#include "Compte.hpp"     // on n'inclut QUE le .hpp, jamais le .cpp

int main() {
    Compte c("Gauthier", 100);
    c.deposer(50);
    std::cout << c.getSolde() << std::endl;
    return 0;
}
```

## Comment ça se compile

```
Compte.cpp ──► compilation ──► Compte.o ──┐
                                          ├──► édition de liens ──► app.exe
main.cpp   ──► compilation ──► main.o   ──┘
```

1. Chaque `.cpp` est compilé **séparément**. Pour compiler `main.cpp`, le compilateur n'a besoin que des déclarations du `.hpp` : il sait que `deposer(double)` existe.
2. L'**éditeur de liens** (*linker*) assemble ensuite les morceaux et relie l'appel `c.deposer(50)` au code qui se trouve dans `Compte.o`.

Ce qui explique les deux erreurs les plus fréquentes :

| Erreur | Étape | Cause |
|---|---|---|
| `'Compte' was not declared` | compilation | `#include "Compte.hpp"` oublié |
| `undefined reference to 'Compte::deposer(double)'` | édition de liens | méthode déclarée mais pas définie, faute de frappe dans `Compte::`, `const` oublié dans le `.cpp`, ou `Compte.cpp` absent de `add_executable` |

## Organisation du projet

```
mon_projet/
├── CMakeLists.txt
└── src/
    ├── main.cpp
    ├── Compte.hpp
    └── Compte.cpp
```

```cmake
cmake_minimum_required(VERSION 3.16)
project(MonProjet CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app
    src/main.cpp
    src/Compte.cpp       # les .cpp seulement
)

target_compile_options(app PRIVATE -Wall -Wextra)
```

```powershell
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
.\build\app.exe
```

Sans CMake : `g++ -std=c++17 -Wall -Wextra src/main.cpp src/Compte.cpp -o app.exe`

L'exemple complet se trouve dans `exemple/` : compile-le avant de faire les exercices.

## Une classe = deux fichiers

Règle simple : **une classe par paire de fichiers**, nommés comme la classe (`Compte.hpp` / `Compte.cpp`).
Exception tolérée : de petites classes très liées (comme les types de trains) peuvent partager un fichier.

## À retenir

- `.hpp` : déclaration + include guard. `.cpp` : définitions avec `NomClasse::`.
- On inclut le `.hpp`, jamais le `.cpp`.
- `const` dans les deux fichiers ; valeurs par défaut uniquement dans le `.hpp`.
- Chaque `.cpp` doit apparaître dans `add_executable`.
- `undefined reference` = problème d'édition de liens : une définition manque.
