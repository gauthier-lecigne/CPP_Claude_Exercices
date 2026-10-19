# Exercice 1 — La bibliothèque, version objet

Au chapitre 09, la bibliothèque était un `std::vector<Livre>` manipulé par des fonctions libres.
On la réécrit avec deux classes liées par une **composition** :

```
Bibliotheque ◆──── 0..* Livre
```

## `Livre` (`src/Livre.hpp`, `src/Livre.cpp`)

| Membre | Rôle |
|---|---|
| `Livre(const std::string& titre, const std::string& auteur, int annee)` | Un livre est disponible à sa création. |
| `std::string getTitre() const`, `getAuteur() const`, `int getAnnee() const` | |
| `bool estDisponible() const` | |
| `std::string getEmprunteur() const` | Chaîne vide si disponible. |
| `bool emprunter(const std::string& personne)` | `false` si déjà emprunté. |
| `bool rendre()` | `false` s'il n'était pas emprunté. |
| `std::string toString() const` | `Le Petit Prince - Saint-Exupery (1943) [disponible]` ou `[emprunte par Lea]` |

## `Bibliotheque` (`src/Bibliotheque.hpp`, `src/Bibliotheque.cpp`)

Attribut privé : `std::vector<Livre> livres;`

| Méthode | Rôle |
|---|---|
| `void ajouter(const Livre& livre)` | |
| `std::size_t getNbLivres() const` | |
| `std::size_t getNbDisponibles() const` | |
| `bool emprunter(const std::string& titre, const std::string& personne)` | Cherche le livre par titre ; `false` s'il n'existe pas ou n'est pas disponible. |
| `bool rendre(const std::string& titre)` | |
| `std::vector<Livre> livresDe(const std::string& auteur) const` | |
| `void afficher() const` | Un livre par ligne, numérotés à partir de 1. |

Une méthode **privée** `Livre* trouver(const std::string& titre);` qui renvoie `nullptr` si le titre n'existe pas évitera de dupliquer la recherche dans `emprunter` et `rendre`.

## Ce que tu dois constater

Compare avec ta version du chapitre 09 :
- les règles (« on ne peut pas emprunter un livre déjà emprunté ») sont **dans** `Livre`, plus éparpillées dans le `main` ;
- le `main` ne touche plus jamais directement au `vector`.

## Résultat attendu

Le `main.cpp` fourni affiche `9/9 tests reussis`, puis le contenu de la bibliothèque.
