/*
 * Exercice 2 — Somme et produit
 *
 * Demande deux nombres entiers, puis affiche leur somme, leur différence
 * et leur produit.
 *
 * Exemple :
 *     Premier nombre : 7
 *     Deuxieme nombre : 3
 *     7 + 3 = 10
 *     7 - 3 = 4
 *     7 * 3 = 21
 *
 * Bonus : lis les deux nombres avec un seul std::cin.
 */

#include <iostream>

int main() {
    int chiffre1;
    std::cout << "premier chiffre : ";
    std::cin >> chiffre1;
    
    int chiffre2;
    std::cout << "premier chiffre : ";
    std::cin >> chiffre2;
    
    std::cout << chiffre1 << " + " << chiffre2 << " = " << chiffre1 + chiffre2 << "\n";
    std::cout << chiffre1 << " - " << chiffre2 << " = " << chiffre1 - chiffre2 << "\n";
    std::cout << chiffre1 << " * " << chiffre2 << " = " << chiffre1 * chiffre2 ;

    return 0;
}
