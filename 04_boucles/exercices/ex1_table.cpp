/*
 * Exercice 1 — Table de multiplication
 *
 * Demande un entier n et affiche sa table de multiplication de 1 à 10.
 *
 * Exemple :
 *     Table de : 7
 *     7 x 1 = 7
 *     7 x 2 = 14
 *     ...
 *     7 x 10 = 70
 *
 * Bonus : affiche ensuite le tableau complet des tables de 1 à 10
 *         (une grille 10 x 10) avec deux boucles imbriquées.
 *         std::setw(4) de <iomanip> aide à aligner les colonnes.
 */

#include <iostream>
#include <iomanip>

int main() {
    int table;
    std::cout << "Entrer un nombre : ";
    std::cin >> table;
    
    for (int i=1; i < 11; i++) {
        std::cout << std::setw(4) << table << " x " << i << " = " << table * i << "\n";
    }
    
    std::cout << "Maintenant le bonus" << "\n";
    
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            std::cout << std::setw(4) << j * i << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
