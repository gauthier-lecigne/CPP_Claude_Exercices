# Exercice 2 — Retour aux trains : la règle 5 pour de vrai

On reconstruit la hiérarchie de trains du projet de cours, proprement, avec le patron **méthode modèle**.

```
                «abstract» Train
            ▲        ▲        ▲        ▲
            │        │        │        │
           TGV      TER      Fret   TrainDeNuit   (étape 2)
```

`Gare` est fournie (`src/Gare.hpp` / `src/Gare.cpp`), ainsi que le `main.cpp` qui contient la simulation.

## `Train` (abstraite) — `src/Train.hpp`, `src/Train.cpp`

**Attributs privés :**

| Attribut | Rôle |
|---|---|
| `id : std::string` | `"TGV 6601"` |
| `trajet : std::vector<const Gare*>` | Gares desservies dans l'ordre (agrégation). |
| `indexGare : std::size_t` | Indice de la dernière gare atteinte. |
| `kmSurSegment : double` | Km parcourus depuis cette gare. |
| `attente : double` | Minutes d'arrêt restantes en gare. |

Constante : `static constexpr double LONGUEUR_SEGMENT_KM = 100.0;`

**Interface publique :**

| Méthode | Virtuelle ? | Rôle |
|---|---|---|
| `Train(const std::string& id, const std::vector<const Gare*>& trajet)` | | |
| `virtual ~Train() = default;` | oui | |
| `void avancer(double minutes)` | **non** | L'algorithme commun (voir ci-dessous). |
| `bool estArrive() const` | non | Vrai quand `indexGare` est la dernière gare. |
| `const Gare* getProchainArret() const` | non | `nullptr` si arrivé. |
| `std::string getId() const` | non | |
| `std::string getPosition() const` | non | `"en gare de Macon"`, `"entre Lyon Part-Dieu et Macon (75 km)"` ou `"arrive a Dijon"`. |
| `virtual std::string getType() const = 0;` | pure | `"TGV"`, `"TER"`, `"Fret"` |
| `virtual double getVitesseMax() const = 0;` | pure | km/h |
| `virtual int getPriorite() const = 0;` | pure | Plus grand = plus prioritaire. |
| `virtual double getTempsArret() const` | oui, **avec valeur par défaut** | `2.0` minutes. |

### L'algorithme de `avancer(minutes)`

```
tant qu'il reste des minutes et que le train n'est pas arrivé :
    si le train attend en gare :
        consommer min(attente, minutes restantes)
    sinon :
        vitesse = getVitesseMax() / 60          (km par minute)
        temps pour finir le segment = (LONGUEUR - kmSurSegment) / vitesse
        si ce temps est supérieur aux minutes restantes :
            avancer de vitesse * minutes restantes ; plus de minutes
        sinon :
            consommer ce temps ; passer à la gare suivante ; kmSurSegment = 0
            si ce n'est pas le terminus : attente = getTempsArret()
```

## Les types concrets — `src/TypesTrain.hpp`, `src/TypesTrain.cpp`

Trois petites classes très proches : on tolère de les regrouper dans un seul fichier.

| Classe | Vitesse | Priorité | Arrêt en gare |
|---|---|---|---|
| `TGV` | 300 | 3 | défaut (2 min) |
| `TER` | 160 | 2 | défaut |
| `Fret` | 100 | 1 | **10 min** (chargement) |

Astuce : `using Train::Train;` dans chaque classe évite de réécrire le constructeur.

## Étape 1

Le `main.cpp` simule 90 minutes par pas de 15. Il affiche, à chaque pas, le tableau de supervision **trié par priorité**. Fais-le fonctionner.

## Étape 2 : ajouter un train de nuit

Crée `src/TrainDeNuit.hpp` / `.cpp` : vitesse 140, priorité 2, **20 minutes** d'arrêt en gare (les passagers dorment, on ne se presse pas).

Ajoute-en un au `vector` (une ligne dans `main`, à l'endroit marqué) et son `.cpp` dans `CMakeLists.txt`.

**Contrainte : tu ne dois modifier ni `Train.hpp`, ni `Train.cpp`, ni la fonction `simuler()`.** Si tu y arrives, la règle 5 du sujet est respectée, et tu sais maintenant l'expliquer à l'oral.

## Résultat attendu (extrait, étape 1)

```
=== t = 30 min ===
[TGV ] TGV 6601   P3  entre Macon et Dijon (40 km)
[TER ] TER 8812   P2  entre Lyon Part-Dieu et Macon (80 km)
[Fret] FRET 42    P1  entre Lyon Part-Dieu et Macon (50 km)
```

Pour le TGV : 20 min pour atteindre Mâcon (100 km à 5 km/min), 2 min d'arrêt, puis 8 min × 5 km/min = 40 km.
