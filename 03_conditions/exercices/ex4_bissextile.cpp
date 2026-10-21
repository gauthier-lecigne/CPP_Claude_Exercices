/*
 * Exercice 4 — Année bissextile
 *
 * Une année est bissextile si :
 *   - elle est divisible par 4 ET pas par 100,
 *   - OU elle est divisible par 400.
 *
 * Demande une année et affiche si elle est bissextile.
 *
 * Tests à faire :
 *     2024 -> bissextile
 *     2023 -> pas bissextile
 *     1900 -> pas bissextile   (divisible par 100 mais pas par 400)
 *     2000 -> bissextile       (divisible par 400)
 *
 * Contrainte : écris la condition en UNE seule expression booléenne,
 *              stockée dans une variable bool.
 */

#include <iostream>

int main() {
    int annee;
    std::cout << "Annee : ";
    std::cin >> annee;
    
    bool estBissextile = (annee % 4 == 0 && annee % 100 != 0) || annee % 400 == 0;
    
    if (estBissextile) {
        std::cout << "Bissextile" << "\n";
    } else {
        std::cout << "Non Bissextile" << "\n";
    }

    return 0;
}
