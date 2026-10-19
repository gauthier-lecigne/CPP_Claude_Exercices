/*
 * Exercice 3 — Récursivité
 *
 * Écris ces trois fonctions RÉCURSIVES (pas de boucle !) :
 *
 *   long long factorielle(int n);
 *       factorielle(0) = 1, factorielle(n) = n * factorielle(n - 1)
 *
 *   int puissance(int base, int exposant);
 *       base^0 = 1, base^e = base * base^(e - 1)
 *
 *   int sommeChiffres(int n);
 *       sommeChiffres(1234) = 1 + 2 + 3 + 4 = 10
 *       Indice : n % 10 donne le dernier chiffre, n / 10 retire ce chiffre.
 *
 * Sortie attendue du main fourni :
 *     5! = 120
 *     20! = 2432902008176640000
 *     2^10 = 1024
 *     sommeChiffres(1234) = 10
 *
 * Question : pourquoi factorielle renvoie-t-elle un long long et pas un int ?
 *            (Essaie avec int et regarde 20!)
 */

#include <iostream>

// TODO

int main() {
    // std::cout << "5! = " << factorielle(5) << std::endl;
    // std::cout << "20! = " << factorielle(20) << std::endl;
    // std::cout << "2^10 = " << puissance(2, 10) << std::endl;
    // std::cout << "sommeChiffres(1234) = " << sommeChiffres(1234) << std::endl;
    return 0;
}
