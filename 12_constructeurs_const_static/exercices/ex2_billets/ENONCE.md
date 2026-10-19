# Exercice 2 — Billets de train : `static`, `const` et destructeur

Écris une classe `Billet` (fichiers `src/Billet.hpp` / `src/Billet.cpp`).

## Spécification

**Attributs :**

| Attribut | Type | Particularité |
|---|---|---|
| `numero` | `const int` | Unique, attribué automatiquement, **ne change jamais** |
| `passager` | `std::string` | |
| `trajet` | `std::string` | Ex. `"Lyon -> Dijon"` |
| `prix` | `double` | Toujours `>= 0` |
| `prochainNumero` | `static int` | Commence à 1000 |
| `nbBilletsActifs` | `static int` | Nombre de billets **actuellement en mémoire** |

**Constante de classe :** `static constexpr double REDUCTION_JEUNE = 0.30;`

**Méthodes :**

| Méthode | Rôle |
|---|---|
| `Billet(const std::string& passager, const std::string& trajet, double prix)` | Attribue `numero = prochainNumero++`, incrémente `nbBilletsActifs`, affiche `"+ billet 1000 cree"`. Prix négatif → 0. |
| `~Billet()` | Décrémente `nbBilletsActifs`, affiche `"- billet 1000 detruit"`. |
| `int getNumero() const`, `double getPrix() const`, … | Getters |
| `void appliquerReductionJeune()` | Prix × (1 − 30 %) |
| `void afficher() const` | `"[1000] Gauthier - Lyon -> Dijon - 45 EUR"` |
| `static int getNbBilletsActifs()` | |

Pour le `const int numero`, la **liste d'initialisation** est obligatoire : essaie d'abord de l'affecter dans le corps du constructeur, et lis l'erreur.

## Le main fourni

Il crée des billets dans des blocs `{ }` différents pour montrer **quand** le destructeur est appelé. Avant de lancer le programme, **écris sur papier** la sortie que tu attends, ligne par ligne. Puis compare.

## Questions (réponds en commentaire dans `Billet.hpp`)

1. Pourquoi `getNbBilletsActifs()` peut-elle être `static`, mais pas `afficher()` ?
2. `afficherBillet(const Billet& b)` dans le main appelle `b.afficher()`. Que se passe-t-il si tu retires le `const` de la méthode `afficher` ?
3. Pourquoi le compilateur refuse-t-il `Billet b2 = b1;` suivi de `b2 = b1;` ? (Indice : regarde l'attribut `numero`.)
