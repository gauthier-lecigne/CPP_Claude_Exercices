# Exercice 2 — Véhicules : `protected` et les limites de l'héritage simple

```
              Vehicule
             ▲        ▲
             │        │
         Voiture    Camion
```

## `Vehicule`

| Membre | Rôle |
|---|---|
| `- marque : std::string`, `- vitesseMax : double`, `- kilometrage : double` | |
| `+ Vehicule(const std::string& marque, double vitesseMax)` | `vitesseMax <= 0` → 50 |
| `+ getMarque() const`, `+ getVitesseMax() const`, `+ getKilometrage() const` | |
| `+ void rouler(double km)` | Ajoute au kilométrage (ignore les valeurs négatives). |
| `+ double tempsTrajet(double km) const` | Durée en heures à vitesse max : `calculerTemps(km, vitesseMax)`. |
| `+ std::string decrire() const` | `Renault (130 km/h, 1200 km)` |
| `# double calculerTemps(double km, double vitesse) const` | **Protégée** : `km / vitesse`. Outil réservé à la famille. |

## `Voiture : public Vehicule`

| Membre | Rôle |
|---|---|
| `- nbPlaces : int` | |
| `+ Voiture(const std::string& marque, double vitesseMax, int nbPlaces)` | |
| `+ std::string decrire() const` | `Voiture Renault (130 km/h, 1200 km), 5 places` — réutilise `Vehicule::decrire()`. |

## `Camion : public Vehicule`

| Membre | Rôle |
|---|---|
| `- chargeMax : double`, `- charge : double` (tonnes) | |
| `+ Camion(const std::string& marque, double vitesseMax, double chargeMax)` | |
| `+ bool charger(double tonnes)` | Refuse si on dépasserait `chargeMax`. |
| `+ void decharger()` | |
| `+ double getCharge() const` | |
| `+ double tempsTrajet(double km) const` | Un camion **chargé à plus de 50 %** roule à 70 % de sa vitesse max. Utilise `calculerTemps` (protégée). |
| `+ std::string decrire() const` | `Camion Volvo (90 km/h, 0 km), charge 12/20 t` |

## Ce que l'exercice met en évidence

La fin du `main` range une voiture et un camion **chargé** dans un `std::vector<Vehicule*>` et appelle `tempsTrajet(450)` sur chacun.

1. Le temps affiché pour le camion est-il correct ? Pourquoi ?
2. Que faudrait-il changer pour que le bon calcul soit utilisé ? (Tu le verras au chapitre 15 : essaie de deviner avant.)
3. Pourquoi `calculerTemps` est-elle `protected` plutôt que `public` ou `private` ?

## Résultat attendu

`9/9 tests reussis`, puis la démonstration du problème.
