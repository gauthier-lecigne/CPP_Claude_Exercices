# Exercice 2 — Une classe `Horaire`

Dans le projet ferroviaire, les horaires étaient de simples `int` (minutes).
Tu vas écrire une vraie classe `Horaire`, comme un horaire de départ « 14:05 ».

## Spécification

Fichiers à créer : `src/Horaire.hpp` et `src/Horaire.cpp`.

**Attribut privé** : un seul, `minutesDepuisMinuit` (`int`, entre 0 et 1439).
Stocker une seule valeur au lieu de « heures + minutes » simplifie énormément les calculs.

**Invariant** : `0 <= minutesDepuisMinuit < 1440` (24 × 60). Un horaire qui dépasse minuit
« repart » à 00:00 : 23:30 + 45 min = 00:15.

| Méthode | Rôle |
|---|---|
| `Horaire(int heures, int minutes)` | `Horaire(14, 5)` → 14:05. Les valeurs trop grandes sont ramenées dans la journée : `Horaire(25, 70)` → 02:10. |
| `int getHeures() const` | 14 |
| `int getMinutes() const` | 5 |
| `void ajouterMinutes(int m)` | Avance de `m` minutes (peut être négatif : recule). Respecte l'invariant. |
| `int minutesJusqua(const Horaire& autre) const` | Minutes entre `*this` et `autre`, **toujours positif ou nul**, en passant minuit si besoin : de 23:50 à 00:10 = 20. |
| `bool estAvant(const Horaire& autre) const` | Comparaison dans la journée. |
| `std::string toString() const` | `"14:05"` (toujours deux chiffres de chaque côté). |

## Aide

Une fonction privée `normaliser()` qui ramène `minutesDepuisMinuit` dans `[0, 1440)` évite de répéter le calcul. Attention : en C++, `-30 % 1440` vaut `-30`. Pour les négatifs, il faut ajouter 1440.

Pour `toString`, tu peux utiliser un `std::ostringstream` (`#include <sstream>`) avec `std::setw(2)` et `std::setfill('0')`, ou construire la chaîne à la main avec `std::to_string`.

## Résultat attendu

Le `main.cpp` fourni contient des tests. Quand tout est juste, il affiche uniquement des `[OK]` et termine par `10/10 tests reussis`.
