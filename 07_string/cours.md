# 07 — Les chaînes de caractères (`std::string`)

`std::string` (`#include <string>`) représente du texte. C'est, en gros,
un `vector<char>` avec des fonctions en plus pour le texte.

## Créer et assembler

```cpp
std::string prenom = "Gauthier";
std::string vide;                         // ""
std::string tirets(10, '-');              // "----------"

std::string salut = "Bonjour " + prenom;  // concaténation avec +
salut += " !";                            // ajout à la fin
```

⚠️ `"Bonjour " + "toi"` ne compile pas : il faut qu'au moins un des deux soit une `std::string`.

## Accéder aux caractères

```cpp
std::string s = "Lyon";
s.size();        // 4  (s.length() est identique)
s[0];            // 'L'  (un char !)
s[s.size() - 1]; // 'n'
s[0] = 'l';      // s devient "lyon"
s.empty();       // false

for (char c : s) {
    std::cout << c << "-";    // l-y-o-n-
}
```

## Les fonctions utiles

```cpp
std::string s = "Lyon Part-Dieu";

s.substr(5, 4);         // "Part"  : 4 caractères à partir de l'indice 5
s.substr(5);            // "Part-Dieu" : jusqu'à la fin
s.find("Dieu");         // 10 : position de la première occurrence
s.find('z');            // std::string::npos : pas trouvé
s.insert(0, "Gare ");   // "Gare Lyon Part-Dieu"
s.erase(0, 5);          // retire 5 caractères à partir de 0
s.replace(0, 4, "LYON");// remplace 4 caractères à partir de 0
```

Tester si `find` a trouvé quelque chose :

```cpp
if (s.find("Dieu") != std::string::npos) {
    std::cout << "Trouve !";
}
```

## Comparer

```cpp
std::string a = "abc", b = "abd";
a == b;     // false
a < b;      // true : ordre alphabétique (en fait, ordre des codes ASCII)
```

⚠️ Les majuscules passent **avant** les minuscules : `"Z" < "a"` est vrai.

## Majuscules, minuscules, chiffres (`#include <cctype>`)

```cpp
std::toupper('a');   // 'A'
std::tolower('B');   // 'b'
std::isalpha('x');   // vrai si lettre
std::isdigit('7');   // vrai si chiffre
std::isspace(' ');   // vrai si espace, tabulation, saut de ligne
```

Ces fonctions renvoient des `int` : on les reconvertit en `char` avec `static_cast<char>(...)`.

## Lire une ligne entière : `getline`

`std::cin >> s` s'arrête au premier espace. Pour lire une phrase :

```cpp
std::string phrase;
std::getline(std::cin, phrase);   // lit toute la ligne, espaces compris
```

⚠️ **Le piège `cin` + `getline`** :

```cpp
int age;
std::string nom;
std::cin >> age;               // l'utilisateur tape "21" puis Entrée
std::getline(std::cin, nom);   // lit... le "Entrée" resté en attente -> nom = ""
```

`cin >> age` lit `21` mais laisse le retour à la ligne dans le tampon. La solution :

```cpp
std::cin >> age;
std::cin.ignore(1000, '\n');   // jette le reste de la ligne
std::getline(std::cin, nom);   // OK
```

## Convertir nombre ↔ texte

```cpp
std::string s = std::to_string(42);    // "42"
int n = std::stoi("123");              // 123
double d = std::stod("3.14");          // 3.14
```

`stoi("abc")` lève une erreur : on verra plus tard comment l'attraper avec `try/catch`.

## À retenir

- `+` pour concaténer, `size()` pour la longueur, `[i]` pour un caractère.
- `find` renvoie `std::string::npos` si rien n'est trouvé.
- `getline` pour lire une ligne, avec `cin.ignore` après un `cin >>`.
- `toupper`, `isdigit`… dans `<cctype>`.
