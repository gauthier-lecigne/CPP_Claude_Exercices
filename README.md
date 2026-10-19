# CPP_Home — Remise à niveau C++

Un parcours progressif pour reprendre les bases du C++ puis passer à la
programmation orientée objet avec des fichiers `.hpp` / `.cpp`.

## Comment utiliser ce dossier

Chaque chapitre contient :

| Fichier / dossier | Rôle |
|---|---|
| `cours.md` | La leçon : à lire en premier (ouvre-le dans VS Code, `Ctrl+Shift+V` pour l'aperçu). |
| `exercices/` | Les énoncés, avec un squelette de code à compléter. |
| `solutions/` | Une correction commentée. **À n'ouvrir qu'après avoir essayé.** |

Méthode conseillée pour chaque exercice :

1. Lis l'énoncé (en haut du fichier ou dans `ENONCE.md`).
2. Écris ton code, compile, teste avec plusieurs valeurs (y compris des cas bizarres : 0, négatif, vide…).
3. Seulement ensuite, compare avec la solution. Si ton code marche mais est différent, c'est normal.

## Progression

### Partie 1 — Les bases (un seul fichier `.cpp` par exercice)

| # | Chapitre | Notions |
|---|---|---|
| 00 | `00_compiler` | Compiler avec g++ et CMake (à lire une fois) |
| 01 | `01_premier_programme` | `main`, `cout`, `cin`, commentaires |
| 02 | `02_variables_types` | `int`, `double`, `char`, `bool`, `string`, `const`, conversions |
| 03 | `03_conditions` | `if` / `else`, opérateurs logiques, `switch` |
| 04 | `04_boucles` | `for`, `while`, `do…while`, `break`, `continue` |
| 05 | `05_fonctions` | Paramètres, retour, prototypes, surcharge, récursivité |
| 06 | `06_vector` | Tableaux, `std::vector`, parcours |
| 07 | `07_string` | Manipulation de chaînes, `getline` |
| 08 | `08_references_pointeurs` | `&`, `*`, passage par référence, `nullptr` |
| 09 | `09_struct` | Regrouper des données avec `struct` |

### Partie 2 — Programmation orientée objet (fichiers `.hpp` + `.cpp`)

| # | Chapitre | Notions |
|---|---|---|
| 10 | `10_premiere_classe` | `class`, `public` / `private`, méthodes, encapsulation |
| 11 | `11_hpp_cpp` | Séparer déclaration et définition, include guards, CMake |
| 12 | `12_constructeurs_const_static` | Liste d'initialisation, `const`, `static`, destructeur |
| 13 | `13_composition` | Des objets dans des objets, composition vs agrégation |
| 14 | `14_heritage` | `: public`, `protected`, appel du constructeur parent |
| 15 | `15_polymorphisme` | `virtual`, `override`, classe abstraite, `unique_ptr` |
| 16 | `16_projet_final` | Projet guidé : gestion d'un parking |

Compte environ 1 h par chapitre de la partie 1 et 1 h 30 à 2 h par chapitre de la partie 2.

## Compiler en deux secondes

Partie 1 (un seul fichier) :

```powershell
g++ -std=c++17 -Wall -Wextra ex1_bonjour.cpp -o ex1.exe
.\ex1.exe
```

Partie 2 (projet avec CMake, depuis le dossier qui contient `CMakeLists.txt`) :

```powershell
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
.\build\app.exe
```

Tous les détails, et les erreurs courantes, sont dans `00_compiler/cours.md`.

## Remarque sur les accents

Les programmes n'affichent pas d'accents (`"Resultat"` au lieu de `"Résultat"`)
parce que la console Windows les affiche mal par défaut. Si tu veux des accents,
tape `chcp 65001` dans PowerShell avant de lancer ton programme.
