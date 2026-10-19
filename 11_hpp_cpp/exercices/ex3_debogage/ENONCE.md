# Exercice 3 — Chasse aux bugs

Ce petit projet contient **quatre erreurs** typiques de la séparation `.hpp` / `.cpp`,
plus un problème de style. Il ne compile pas.

Ta mission : le faire compiler et afficher

```
Gare Lyon Part-Dieu : 4 quais
Gare Macon : 2 quais
```

## Méthode

1. Lance la compilation.
2. Lis **la première** erreur uniquement. Note dans le tableau ci-dessous le message, la cause, la correction.
3. Corrige, recompile, recommence.

| # | Message (résumé) | Fichier / ligne | Cause | Correction |
|---|---|---|---|---|
| 1 | | | | |
| 2 | | | | |
| 3 | | | | |
| 4 | | | | |

Remarque : une des erreurs n'apparaît **qu'à l'édition de liens**, une fois toutes les autres corrigées. Note bien la différence entre une erreur de compilation et une erreur d'édition de liens.

## Le problème de style

Il ne provoque pas d'erreur, mais un relecteur le refuserait. Une ligne dans un `.hpp` ne devrait jamais s'y trouver. Laquelle, et pourquoi ?
