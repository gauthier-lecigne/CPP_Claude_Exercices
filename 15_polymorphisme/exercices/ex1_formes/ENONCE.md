# Exercice 1 — Formes géométriques

```
                 «abstract» Forme
               ▲        ▲         ▲
               │        │         │
           Cercle   Rectangle   Triangle
                        ▲
                        │
                      Carre
```

## `Forme` (abstraite) — `src/Forme.hpp`, `src/Forme.cpp`

| Membre | Rôle |
|---|---|
| `+ virtual ~Forme() = default;` | |
| `+ virtual std::string nom() const = 0;` | |
| `+ virtual double aire() const = 0;` | |
| `+ virtual double perimetre() const = 0;` | |
| `+ std::string decrire() const` | **Non virtuelle.** `Cercle : aire = 3.14159, perimetre = 6.28319`. Elle appelle les trois méthodes virtuelles. |

## Les formes concrètes (une paire de fichiers chacune)

| Classe | Constructeur | Calculs |
|---|---|---|
| `Cercle` | `explicit Cercle(double rayon)` (≤ 0 → 1) | aire = π r², périmètre = 2 π r. π : `M_PI` n'est pas standard, définis `static constexpr double PI = 3.14159265358979;` |
| `Rectangle` | `Rectangle(double largeur, double hauteur)` (≤ 0 → 1) | |
| `Triangle` | `Triangle(double a, double b, double c)` | Si les côtés ne forment pas un triangle (chaque côté doit être strictement inférieur à la somme des deux autres), utilise 1, 1, 1. Aire par la formule de Héron : `s = (a+b+c)/2`, `aire = sqrt(s(s-a)(s-b)(s-c))`. |
| `Carre : public Rectangle` | `explicit Carre(double cote)` | Ne redéfinit **que** `nom()`. L'aire et le périmètre sont hérités de `Rectangle`. |

Mets `override` partout où c'est pertinent.

## Fonctions libres (dans `main.cpp`, à écrire)

```cpp
double aireTotale(const std::vector<std::unique_ptr<Forme>>& formes);
const Forme* plusGrande(const std::vector<std::unique_ptr<Forme>>& formes);  // nullptr si vide
```

Elles sont déjà appelées par le `main` : écris-les au-dessus.

## Étape 2 : prouver le principe ouvert/fermé

Une fois tout fonctionnel, ajoute une classe `Hexagone` (régulier, de côté `c`) :
aire = `3 * sqrt(3) / 2 * c²`, périmètre = `6c`.

Ajoute-la au `vector` dans le `main` et au `CMakeLists.txt`.
**Contrainte : tu ne dois modifier ni `Forme`, ni `aireTotale`, ni `plusGrande`, ni la boucle d'affichage.**

## Questions (en commentaire dans `Forme.hpp`)

1. Pourquoi `decrire()` n'a-t-elle pas besoin d'être virtuelle ?
2. Que se passe-t-il si tu écris `Forme f;` ? Et `std::vector<Forme> v;` puis `v.push_back(Cercle(1));` ?
3. Retire `override` de `Cercle::aire` et ajoute une faute (`double aire()` sans `const`). Que se passe-t-il ? Remets `override` : quelle différence ?

## Résultat attendu

`8/8 tests reussis`, puis la liste des formes triée par aire décroissante.
