# 16 — Projet final : gestion d'un parking

Ce projet réutilise **tout** ce que tu as vu : classes, `.hpp` / `.cpp`, composition,
agrégation, héritage, polymorphisme, `unique_ptr`. Il ressemble volontairement au
projet ferroviaire (des « places limitées » comme les quais, des « types » qui se
comportent différemment comme les trains) pour que tu puisses transposer.

Compte 4 à 6 heures. Avance **étape par étape** et ne passe à la suivante que quand les tests de l'étape sont tous `[OK]`.

## Le domaine

Un parking possède un nombre fixe de places de trois tailles (petite, normale, grande).
Des véhicules entrent et sortent ; à la sortie, le parking calcule le prix.

**Règles :**

1. Chaque type de véhicule a son **tarif horaire**, sa **taille de place minimale** et son **plafond journalier**.

   | Type | Tarif / heure | Place minimale | Plafond |
   |---|---|---|---|
   | Moto | 1,00 € | petite | 25 € (défaut) |
   | Voiture | 2,00 € | normale | 25 € (défaut) |
   | Camionnette | 3,50 € | grande | **40 €** |

2. Calcul du prix (identique pour tous) : les **30 premières minutes sont gratuites** ; au-delà, on paie chaque **heure entamée** depuis l'entrée (31 min → 1 h, 61 min → 2 h) ; le prix ne dépasse jamais le plafond.
3. Un véhicule peut se garer sur une place **de sa taille ou plus grande**. Le parking choisit **la plus petite place libre compatible** (on ne gâche pas une grande place pour une moto).
4. Un véhicule déjà garé ne peut pas entrer une deuxième fois.
5. **Ajouter un type de véhicule ne doit pas obliger à modifier `Parking` ni `Place`.**

Les heures sont des `int` en minutes depuis l'ouverture (0 = ouverture, 90 = 1 h 30 après).

## Diagramme de classes

```
                     «abstract» Vehicule
                 - immatriculation : string
                 + calculerPrix(duree) : double          (non virtuelle)
                 + getType() : string                    {abstract}
                 + getTarifHoraire() : double            {abstract}
                 + getTailleMinimale() : TaillePlace     {abstract}
                 + getPlafond() : double                 (virtuelle, défaut 25)
                  ▲            ▲              ▲
                  │            │              │
                Moto        Voiture      Camionnette
                               ▲
                               │
                       VoitureElectrique  (étape 5)


 Parking ◆────── 1..* Place ─────────▷ 0..1 Vehicule
 - nom                - numero           (agrégation : la place connaît le
 - places             - taille            véhicule, elle ne le possède pas)
 - recette            - occupant : const Vehicule*
                      - heureEntree
```

**Qui possède les véhicules ?** Ni le parking ni les places : ils appartiennent à leurs
conducteurs. Dans le programme, c'est le `main` qui les possède dans un
`std::vector<std::unique_ptr<Vehicule>>` ; les places ne gardent qu'un `const Vehicule*`.

---

## Étape 1 — La hiérarchie `Vehicule`

Fichiers : `TaillePlace.hpp`, `Vehicule.hpp/.cpp`, `TypesVehicule.hpp/.cpp`.

`TaillePlace.hpp` contient seulement :

```cpp
enum class TaillePlace { Petite = 1, Normale = 2, Grande = 3 };
```

Pour comparer deux tailles : `static_cast<int>(a) >= static_cast<int>(b)`. Ajoute aussi une fonction
`std::string tailleEnTexte(TaillePlace t);` (déclarée `inline` dans le `.hpp` si tu veux la définir directement dedans).

`Vehicule` (abstraite) :

| Membre | Rôle |
|---|---|
| `explicit Vehicule(const std::string& immatriculation)` | |
| `virtual ~Vehicule() = default;` | |
| `std::string getImmatriculation() const` | |
| `double calculerPrix(int dureeMinutes) const` | **Non virtuelle** : applique la règle 2 en appelant `getTarifHoraire()` et `getPlafond()`. |
| `std::string decrire() const` | `Voiture AB-123-CD` |
| `virtual std::string getType() const = 0;` | |
| `virtual double getTarifHoraire() const = 0;` | |
| `virtual TaillePlace getTailleMinimale() const = 0;` | |
| `virtual double getPlafond() const;` | 25 par défaut. |

Puis `Moto`, `Voiture`, `Camionnette` (dans `TypesVehicule`).

Active les tests : `#define ETAPE 1` dans `main.cpp`, et les lignes correspondantes du `CMakeLists.txt`.

## Étape 2 — `Place`

| Membre | Rôle |
|---|---|
| `Place(int numero, TaillePlace taille)` | |
| `int getNumero() const`, `TaillePlace getTaille() const` | |
| `bool estLibre() const` | |
| `bool peutAccueillir(const Vehicule& v) const` | Libre **et** assez grande. |
| `bool occuper(const Vehicule& v, int heure)` | `false` si impossible. |
| `const Vehicule* getOccupant() const` | `nullptr` si libre. |
| `int getHeureEntree() const` | |
| `void liberer()` | |

## Étape 3 — `Parking`

| Membre | Rôle |
|---|---|
| `explicit Parking(const std::string& nom)` | |
| `void ajouterPlaces(TaillePlace taille, int nombre)` | Les numéros se suivent : 1, 2, 3… |
| `int entrer(const Vehicule& v, int heure)` | Numéro de la place attribuée (règle 3), ou `-1` si refusé (complet ou règle 4). |
| `double sortir(const std::string& immatriculation, int heure)` | Libère la place, ajoute le prix à la recette et le renvoie ; `-1` si ce véhicule n'est pas dans le parking. |
| `int getNbPlacesLibres() const` | |
| `int getNbPlacesLibres(TaillePlace taille) const` | Surcharge. |
| `double getTauxOccupation() const` | Entre 0 et 1. |
| `double getRecette() const` | |
| `void afficherEtat(int heure) const` | Le tableau de bord (voir ci-dessous). |

Méthodes privées conseillées : `Place* trouverPlaceLibre(const Vehicule& v);` et `Place* trouverPlaceDe(const std::string& immat);`.

Pour la règle 3, le plus simple est de garder les places **triées par taille** et de prendre la première compatible.

## Étape 4 — Le tableau de bord

`afficherEtat(heure)` affiche par exemple :

```
===== Parking Lille Europe - 02:15 =====
Occupation : 4/6 (67 %)    Recette : 6 EUR
 #1 [petite ]  Moto AA-111-AA        depuis 00:00 (2h15)  a payer : 3 EUR
 #2 [petite ]  libre
 #3 [normale]  Voiture BB-222-BB     depuis 00:30 (1h45)  a payer : 4 EUR
 ...
```

Le prix « à payer » est celui qu'il faudrait payer en sortant maintenant : `calculerPrix(heure - heureEntree)`.

Puis active `#define ETAPE 4` : le `main` déroule un scénario complet.

## Étape 5 — Prouver la règle 5

Ajoute une `VoitureElectrique` qui **hérite de `Voiture`** : tarif 1 €/h, plafond 12 €, type `"Voiture electrique"`.
Elle a besoin d'une place normale, comme une voiture : elle n'a donc rien à redéfinir pour ça.

**Contrainte : `Parking`, `Place` et `Vehicule` ne doivent pas changer d'une ligne.**

## Étape 6 — Bonus (au choix)

- Un **menu interactif** (entrer, sortir, afficher, avancer l'horloge, quitter), comme au chapitre 05.
- Un **historique** des sorties : une `struct Sortie { std::string immat; std::string type; int duree; double prix; };` stockée dans `Parking`, et une méthode qui affiche le chiffre d'affaires **par type de véhicule**.
- Un **abonnement** : un `Abonne` (décorateur ou attribut ?) qui ne paie rien. Où mettre cette règle sans toucher à `calculerPrix` ? Il y a plusieurs bonnes réponses : choisis-en une et justifie-la.

---

## Grille d'auto-évaluation

| Critère | ✔ |
|---|---|
| Chaque classe a son `.hpp` (avec include guard) et son `.cpp` | |
| Attributs `private`, méthodes de lecture `const` | |
| Listes d'initialisation dans tous les constructeurs | |
| `Vehicule` est abstraite, avec un destructeur `virtual` | |
| `override` sur toutes les redéfinitions | |
| `calculerPrix` n'est **pas** virtuelle (méthode modèle) | |
| Aucun `if (type == ...)` dans `Parking` ou `Place` | |
| Étape 5 réalisée sans modifier `Parking`, `Place`, `Vehicule` | |
| Compilation sans **aucun** warning avec `-Wall -Wextra` | |
| Tu sais expliquer à l'oral chaque losange et chaque triangle du diagramme | |

La correction complète se trouve dans `solution/`. Le point de départ (tests + CMake) est dans `depart/`.
