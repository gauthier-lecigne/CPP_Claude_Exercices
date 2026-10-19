#include <iostream>
#include <string>

// Décale une lettre en restant dans l'alphabet qui commence à "base" ('a' ou 'A').
char decaler(char c, int k, char base) {
    int position = c - base;
    int nouvelle = (position + k) % 26;
    if (nouvelle < 0) {
        nouvelle += 26;   // en C++, -1 % 26 vaut -1 (et pas 25)
    }
    return static_cast<char>(base + nouvelle);
}

std::string chiffrer(const std::string& texte, int k) {
    std::string resultat = texte;   // copie, puis on modifie les lettres
    for (char& c : resultat) {      // & : on modifie directement la copie
        if (c >= 'a' && c <= 'z') {
            c = decaler(c, k, 'a');
        } else if (c >= 'A' && c <= 'Z') {
            c = decaler(c, k, 'A');
        }
        // sinon : on ne touche pas au caractère
    }
    return resultat;
}

std::string dechiffrer(const std::string& texte, int k) {
    return chiffrer(texte, -k);
}

int main() {
    std::string texte;
    int k = 0;

    std::cout << "Texte : ";
    std::getline(std::cin, texte);
    std::cout << "Decalage : ";
    std::cin >> k;

    std::string code = chiffrer(texte, k);
    std::cout << "Chiffre : " << code << std::endl;
    std::cout << "Dechiffre : " << dechiffrer(code, k) << std::endl;
    return 0;
}
