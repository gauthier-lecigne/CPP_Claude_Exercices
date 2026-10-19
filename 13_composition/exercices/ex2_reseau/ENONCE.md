# Exercice 2 — Un réseau ferroviaire : composition **et** agrégation

On reprend le domaine du projet de cours, avec trois classes :

```
Reseau ◆──── 0..* Gare
Reseau ◆──── 0..* Ligne
Ligne  ◇──── 2..* Gare      (une gare peut être desservie par plusieurs lignes)
```

## `Gare` (`src/Gare.hpp`, `src/Gare.cpp`)

| Membre | Rôle |
|---|---|
| `Gare(const std::string& nom, int nbQuais)` | `nbQuais < 1` → 1 |
| `std::string getNom() const`, `int getNbQuais() const` | |

## `Ligne` (`src/Ligne.hpp`, `src/Ligne.cpp`)

Attributs : `std::string nom;` et `std::vector<const Gare*> gares;` (agrégation).

Dans `Ligne.hpp`, utilise une **déclaration anticipée** `class Gare;` au lieu d'inclure `Gare.hpp`.

| Méthode | Rôle |
|---|---|
| `explicit Ligne(const std::string& nom)` | |
| `std::string getNom() const` | |
| `void ajouterGare(const Gare* gare)` | Ignore `nullptr`, et refuse d'ajouter deux fois de suite la même gare. |
| `bool dessert(const std::string& nomGare) const` | |
| `std::size_t getNbGares() const` | |
| `const Gare* getTerminus() const` | Dernière gare, ou `nullptr` si la ligne est vide. |
| `std::string toString() const` | `Ligne A : Lyon Part-Dieu -> Macon -> Dijon` |

## `Reseau` (`src/Reseau.hpp`, `src/Reseau.cpp`)

Attributs : `std::vector<std::unique_ptr<Gare>> gares;` et `std::vector<Ligne> lignes;`.

| Méthode | Rôle |
|---|---|
| `const Gare* ajouterGare(const std::string& nom, int nbQuais)` | Crée la gare (si le nom n'existe pas déjà) et renvoie un pointeur vers elle. Si elle existe, renvoie l'existante. |
| `const Gare* trouverGare(const std::string& nom) const` | `nullptr` si absente. |
| `bool ajouterLigne(const std::string& nom, const std::vector<std::string>& nomsGares)` | Crée une ligne à partir de noms de gares. Renvoie `false` (et ne crée rien) si une des gares n'existe pas. |
| `std::vector<std::string> lignesPassantPar(const std::string& nomGare) const` | Noms des lignes qui desservent cette gare. |
| `void afficher() const` | Toutes les gares puis toutes les lignes. |

## Questions (réponds en commentaire dans `Reseau.hpp`)

1. Pourquoi `std::vector<std::unique_ptr<Gare>>` et pas `std::vector<Gare>` ? Que se passerait-il pour les lignes déjà créées lors d'un nouvel `ajouterGare` ?
2. Pourquoi la `Ligne` ne doit-elle jamais faire `delete` sur ses gares ?
3. Dans quel ordre le `Reseau` doit-il détruire ses attributs pour qu'aucune ligne ne pointe vers une gare déjà détruite ? Vérifie que l'ordre de déclaration de tes attributs le garantit.

## Résultat attendu

Le `main.cpp` fourni affiche `10/10 tests reussis` puis le réseau.
