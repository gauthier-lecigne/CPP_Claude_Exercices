# Exercice 1 — `Personne`, `Etudiant`, `Professeur`

```
            Personne
           ▲        ▲
           │        │
      Etudiant   Professeur
```

Une classe par paire de fichiers dans `src/`.

## `Personne`

| Membre | Rôle |
|---|---|
| `- nom : std::string`, `- age : int` | `age < 0` → 0 |
| `+ Personne(const std::string& nom, int age)` | |
| `+ getNom() const`, `+ getAge() const` | |
| `+ void anniversaire()` | âge + 1 |
| `+ void sePresenter() const` | `Je m'appelle Gauthier, j'ai 21 ans.` |

## `Etudiant : public Personne`

| Membre | Rôle |
|---|---|
| `- ecole : std::string`, `- notes : std::vector<double>` | |
| `+ Etudiant(const std::string& nom, int age, const std::string& ecole)` | Appelle le constructeur de `Personne`. |
| `+ getEcole() const` | |
| `+ void ajouterNote(double note)` | Ignore les notes hors de [0, 20]. |
| `+ double moyenne() const` | 0 si aucune note. |
| `+ void sePresenter() const` | Appelle `Personne::sePresenter()` puis affiche `J'etudie a SUPINFO (moyenne : 14.5).` |

## `Professeur : public Personne`

| Membre | Rôle |
|---|---|
| `- matiere : std::string`, `- salaire : double` | |
| `+ Professeur(const std::string& nom, int age, const std::string& matiere, double salaire)` | |
| `+ getMatiere() const` | |
| `+ void augmenter(double pourcentage)` | Ignore les pourcentages négatifs. |
| `+ double getSalaire() const` | |
| `+ void sePresenter() const` | Version de la mère, puis `J'enseigne le C++.` |

## Questions (réponds en commentaire dans `main.cpp`)

La fin du `main` fourni appelle `presenterTout(...)` avec une `Personne&` qui désigne en réalité un `Etudiant`.

1. Quelle version de `sePresenter` est appelée ? Pourquoi ?
2. Dans `Etudiant::sePresenter`, pourquoi ne peux-tu pas écrire directement `std::cout << nom;` ? Donne deux façons de corriger, et dis laquelle tu préfères.
3. Ajoute un `std::cout` dans chaque constructeur et destructeur. Dans quel ordre s'affichent-ils pour un `Etudiant` ?

## Résultat attendu

`8/8 tests reussis`, puis les présentations.
