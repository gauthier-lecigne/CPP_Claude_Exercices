# 09 — Regrouper des données : `struct`

Jusqu'ici, pour décrire un étudiant, il fallait plusieurs variables séparées
(`nom`, `age`, `moyenne`…). Une `struct` les **regroupe en un seul type**.

## Définir et utiliser une struct

```cpp
struct Etudiant {
    std::string nom;
    int age;
    double moyenne;
};   // ⚠️ le point-virgule est obligatoire

int main() {
    Etudiant e;
    e.nom = "Gauthier";
    e.age = 21;
    e.moyenne = 14.5;

    std::cout << e.nom << " a " << e.age << " ans" << std::endl;
}
```

- `Etudiant` est maintenant un **type**, comme `int` ou `std::string`.
- On accède à un champ avec le point : `e.nom`.
- Avec un pointeur, on utilise la flèche : `p->nom`.

## Initialiser en une ligne

```cpp
Etudiant e = {"Gauthier", 21, 14.5};   // dans l'ordre des champs
Etudiant f{"Lea", 20, 16.0};           // même chose
```

Valeurs par défaut des champs :

```cpp
struct Point {
    double x = 0.0;
    double y = 0.0;
};

Point origine;              // x = 0, y = 0
Point p{3.0, 4.0};
```

## Des struct dans des fonctions

```cpp
void afficher(const Etudiant& e) {     // const& : pas de copie, pas de modification
    std::cout << e.nom << " (" << e.moyenne << ")\n";
}

void ajouterBonus(Etudiant& e, double bonus) {   // & : on modifie l'original
    e.moyenne += bonus;
}

Point milieu(const Point& a, const Point& b) {   // on peut renvoyer une struct
    return {(a.x + b.x) / 2, (a.y + b.y) / 2};
}
```

## Des struct dans des vectors

```cpp
std::vector<Etudiant> promo = {
    {"Gauthier", 21, 14.5},
    {"Lea", 20, 16.0},
    {"Hugo", 22, 11.0},
};

promo.push_back({"Ines", 21, 13.5});

for (const Etudiant& e : promo) {
    afficher(e);
}
```

## Des struct dans des struct

```cpp
struct Date {
    int jour, mois, annee;
};

struct Evenement {
    std::string titre;
    Date date;            // une struct contient une autre struct
};

Evenement e{"Partiel C++", {12, 11, 2026}};
std::cout << e.date.jour;   // 12
```

## Les `enum class`

Souvent associées aux struct, elles définissent un type avec un ensemble fini de valeurs :

```cpp
enum class Statut { Present, Absent, Retard };

struct Appel {
    std::string nom;
    Statut statut;
};

Appel a{"Gauthier", Statut::Retard};
if (a.statut == Statut::Retard) { ... }
```

Bien plus clair et plus sûr qu'un `int` où « 0 = présent, 1 = absent… ».

## Vers les classes

Une `struct` ne fait que **stocker** : n'importe qui peut écrire `e.moyenne = -50;`.
Rien n'empêche les valeurs incohérentes. Pour protéger les données et y attacher
des comportements, on passe aux **classes** : c'est la partie 2.

En C++, `struct` et `class` sont presque identiques. La seule différence : dans une `struct`
tout est `public` par défaut, dans une `class` tout est `private` par défaut.
Par convention, on utilise `struct` pour des **données simples** et `class` dès qu'il y a des **règles à protéger**.

## À retenir

- `struct Nom { champs };` crée un nouveau type.
- `.` pour accéder à un champ, `->` via un pointeur.
- Passe les struct en `const&` (lecture) ou `&` (modification).
- `std::vector<MaStruct>` est un outil extrêmement courant.
