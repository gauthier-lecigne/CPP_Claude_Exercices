/*
 * Exercice 2 — Nombres premiers
 *
 * Un nombre premier est un entier >= 2 divisible uniquement par 1 et par
 * lui-même (2, 3, 5, 7, 11, 13...).
 *
 * 1. Écris  bool estPremier(int n);
 *    Indice : teste les diviseurs de 2 jusqu'à ce que d * d > n.
 *             (Pourquoi pas jusqu'à n ? Réfléchis-y.)
 *
 * 2. Écris  void afficherPremiers(int limite);
 *    qui affiche tous les nombres premiers <= limite, séparés par un espace.
 *
 * 3. Dans le main, demande une limite et appelle afficherPremiers.
 *
 * Exemple :
 *     Limite : 30
 *     2 3 5 7 11 13 17 19 23 29
 *
 * Contrainte : utilise des prototypes en haut du fichier et place les
 *              définitions APRÈS le main.
 */

#include <iostream>

bool estPremier(int n);
void afficherPremiers(int limite);


int main() {
    int limite;
    std::cout << "Limite : ";
    std::cin >> limite;
    afficherPremiers(limite);

    return 0;
}


bool estPremier(int n) {
    if (n < 2) {
        return false;
    } else {
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
    }
    return true;
}

void afficherPremiers(int limite) {
    if (limite < 2) {
        std::cout << "pas de nombres premiers" << "\n";
    } else {
        for (int i = 2; i <= limite; i++) {
            if (estPremier(i)) {
                std::cout << i << " ";
            }
        }
    }
    std::cout << "\n";
}
