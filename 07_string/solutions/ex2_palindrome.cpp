#include <cctype>
#include <iostream>
#include <string>

bool estPalindrome(const std::string& s) {
    std::size_t n = s.size();
    // Il suffit d'aller jusqu'à la moitié.
    for (std::size_t i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) {
            return false;
        }
    }
    return true;
}

std::string nettoyer(const std::string& s) {
    std::string resultat;
    for (char c : s) {
        unsigned char uc = static_cast<unsigned char>(c);
        if (std::isalnum(uc)) {
            resultat += static_cast<char>(std::tolower(uc));
        }
    }
    return resultat;
}

int main() {
    std::string ligne;
    std::cout << "Phrases a tester (ligne vide pour finir) :" << std::endl;

    while (std::getline(std::cin, ligne) && !ligne.empty()) {
        if (estPalindrome(nettoyer(ligne))) {
            std::cout << "  -> palindrome" << std::endl;
        } else {
            std::cout << "  -> pas palindrome" << std::endl;
        }
    }
    return 0;
}
