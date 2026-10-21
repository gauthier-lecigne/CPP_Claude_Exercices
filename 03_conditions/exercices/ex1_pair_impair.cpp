/*
 * Exercice 1 — Pair ou impair, positif ou négatif
 *
 * Demande un entier et affiche :
 *   - s'il est pair ou impair ;
 *   - s'il est positif, négatif ou nul.
 *
 * Exemple :
 *     Un entier : -7
 *     -7 est impair
 *     -7 est negatif
 *
 * Teste avec 0, 4, -7, -10.
 * Attention : en C++, -7 % 2 vaut -1 (et pas 1). Ta condition doit
 * marcher quand même.
 */

#include <iostream>

int main() {
    int chiffre;
    std::cout << "Votre chiffre : ";
    std::cin >> chiffre;
    
    bool PAIR = (chiffre % 2 == 0);
    
    if (PAIR) {
        std::cout << "Votre chiffre est pair" << "\n";
    } else {
        std::cout << "Votre chiffre est impair" << "\n";
    }
    
    
    if (chiffre < 0) {
        std::cout << "Votre chiffre est negatif" << "\n";
    } else if (chiffre > 0) {
        std::cout << "Votre chiffre est positif" << "\n";
    } else {
        std::cout << "Votre chiffre est nul" << "\n";
    }

    return 0;
}
