# 00 — Compiler un programme C++

Le C++ est un langage **compilé** : on écrit du texte (`.cpp`), un programme appelé
*compilateur* (`g++`) le traduit en un exécutable (`.exe`), puis on lance l'exécutable.

```
ex1.cpp  ──g++──►  ex1.exe  ──►  le programme tourne
```

Si tu modifies `ex1.cpp`, il faut **recompiler** avant de relancer, sinon tu exécutes l'ancienne version.

## 1. Compiler un seul fichier avec g++

```powershell
g++ -std=c++17 -Wall -Wextra ex1.cpp -o ex1.exe
.\ex1.exe
```

| Option | Signification |
|---|---|
| `-std=c++17` | Utilise la norme C++17 (moderne, celle de tous ces exercices). |
| `-Wall -Wextra` | Active les avertissements. **Garde-les toujours** : ils signalent beaucoup de bugs. |
| `-o ex1.exe` | Nom de l'exécutable produit. |

Astuce : si tu as plusieurs fichiers `.cpp` sans CMake :

```powershell
g++ -std=c++17 -Wall -Wextra main.cpp Compte.cpp -o app.exe
```

On liste **les `.cpp` seulement**, jamais les `.hpp` : ils sont inclus automatiquement par `#include`.

## 2. Compiler un projet avec CMake

Dès qu'il y a plusieurs fichiers, on décrit le projet dans un `CMakeLists.txt` :

```cmake
cmake_minimum_required(VERSION 3.16)
project(MonProjet CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(app
    src/main.cpp
    src/Compte.cpp
)

target_compile_options(app PRIVATE -Wall -Wextra)
```

Puis, **depuis le dossier qui contient `CMakeLists.txt`** :

```powershell
cmake -S . -B build -G "MinGW Makefiles"   # une seule fois : configuration
cmake --build build                         # à chaque modification : compilation
.\build\app.exe                             # exécution
```

Si tu ajoutes un nouveau `.cpp`, ajoute-le dans `add_executable(...)` puis relance `cmake --build build`.

## 3. Lire une erreur de compilation

```
main.cpp:7:5: error: 'cout' was not declared in this scope
```

- `main.cpp` : le fichier ;
- `7:5` : ligne 7, colonne 5 ;
- le message.

Règles d'or :
1. **Lis la première erreur, pas la dernière.** Une erreur en cascade en provoque souvent 20 autres.
2. Regarde aussi la ligne **juste au-dessus** : un `;` oublié est signalé sur la ligne suivante.

## 4. Les erreurs que tu vas rencontrer

| Message | Cause probable |
|---|---|
| `expected ';' before ...` | Point-virgule oublié à la fin de la ligne précédente. |
| `'cout' was not declared in this scope` | `#include <iostream>` oublié, ou `std::` oublié. |
| `'string' was not declared` | `#include <string>` oublié, ou `std::string`. |
| `undefined reference to 'Compte::deposer(double)'` | La méthode est **déclarée** dans le `.hpp` mais **pas définie** dans le `.cpp`, ou le `.cpp` n'est pas dans `add_executable`. |
| `multiple definition of 'main'` | Deux fichiers contiennent un `main()`. |
| `redefinition of 'class Compte'` | Include guard oublié dans le `.hpp`. |
| `Cannot find source file: src/X.cpp` (CMake) | Le fichier n'est pas à l'endroit écrit dans `CMakeLists.txt`. |
| `Le terme «.\app.exe» n'est pas reconnu` | L'exécutable est dans `build\`, lance `.\build\app.exe`. |
| `cannot open output file ex1.exe: Permission denied` | Le programme tourne encore dans un autre terminal : ferme-le. |

## 5. Le programme minimal

```cpp
#include <iostream>

int main() {
    std::cout << "Ca compile !" << std::endl;
    return 0;
}
```

Copie-le dans un fichier `test.cpp`, compile-le et lance-le. Si ça affiche « Ca compile ! », ton installation fonctionne et tu peux commencer le chapitre 01.
