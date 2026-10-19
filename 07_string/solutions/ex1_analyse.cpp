#include <cctype>
#include <iostream>
#include <string>

bool estVoyelle(char c) {
    char m = static_cast<char>(std::tolower(c));
    return m == 'a' || m == 'e' || m == 'i' || m == 'o' || m == 'u' || m == 'y';
}

int compterVoyelles(const std::string& s) {
    int n = 0;
    for (char c : s) {
        if (estVoyelle(c)) {
            n++;
        }
    }
    return n;
}

int compterChiffres(const std::string& s) {
    int n = 0;
    for (char c : s) {
        // isdigit attend un unsigned char : le cast évite un bug avec les accents.
        if (std::isdigit(static_cast<unsigned char>(c))) {
            n++;
        }
    }
    return n;
}

// Version robuste (bonus) : un mot commence quand on passe
// d'un espace (ou du début) à un caractère qui n'est pas un espace.
int compterMots(const std::string& s) {
    int mots = 0;
    bool dansUnMot = false;
    for (char c : s) {
        if (std::isspace(static_cast<unsigned char>(c))) {
            dansUnMot = false;
        } else if (!dansUnMot) {
            dansUnMot = true;
            mots++;
        }
    }
    return mots;
}

int main() {
    std::string phrase;
    std::cout << "Phrase : ";
    std::getline(std::cin, phrase);

    std::cout << "Longueur : " << phrase.size() << std::endl;
    std::cout << "Voyelles : " << compterVoyelles(phrase) << std::endl;
    std::cout << "Chiffres : " << compterChiffres(phrase) << std::endl;
    std::cout << "Mots : " << compterMots(phrase) << std::endl;
    return 0;
}
