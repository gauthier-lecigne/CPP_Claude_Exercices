# Exercice 1 — Séparer `CompteBancaire`

Reprends ta classe `CompteBancaire` du chapitre 10 (exercice 1) et répartis-la
dans deux fichiers :

- `src/CompteBancaire.hpp` : la déclaration, avec include guard ;
- `src/CompteBancaire.cpp` : toutes les définitions, avec `CompteBancaire::`.

Le `main.cpp` et le `CMakeLists.txt` sont fournis : **ne les modifie pas**.
Ton travail est terminé quand le projet compile sans avertissement et affiche :

```
Gauthier : 100 EUR (0 operations)
Lea : 0 EUR (0 operations)
Retrait de 500 refuse
Gauthier : 120 EUR (2 operations)
Lea : 30 EUR (1 operations)
Virement refuse
```

## Compiler

```powershell
cmake -S . -B build -G "MinGW Makefiles"
cmake --build build
.\build\app.exe
```

## Points de vigilance

- Le `const` des getters et de `afficher` doit apparaître dans les **deux** fichiers.
- `<iostream>` n'est utile qu'à `afficher` : inclus-le dans le `.cpp`, pas dans le `.hpp`.
- Si tu obtiens `undefined reference to ...`, relis la section correspondante du cours.
