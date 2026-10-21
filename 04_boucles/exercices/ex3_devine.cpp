/*
 * Exercice 3 — Devine le nombre
 *
 * Le programme choisit un nombre secret au hasard entre 1 et 100.
 * L'utilisateur propose des nombres ; à chaque essai, le programme répond
 * "Plus grand", "Plus petit" ou "Gagne !".
 * À la fin, affiche le nombre d'essais.
 *
 * Exemple :
 *     Ta proposition : 50
 *     Plus petit
 *     Ta proposition : 25
 *     Plus grand
 *     Ta proposition : 37
 *     Gagne en 3 essais !
 *
 * Pour tirer un nombre au hasard en C++ moderne (déjà écrit ci-dessous) :
 *     std::random_device rd;
 *     std::mt19937 gen(rd());
 *     std::uniform_int_distribution<int> dist(1, 100);
 *     int secret = dist(gen);
 *
 * Bonus : limite à 7 essais. Si l'utilisateur échoue, révèle le nombre.
 */

#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    int secret = dist(gen);
    int guess;
    int nb_essais = 0;

    do  {
        std::cout << "Votre chiffre : ";
        std::cin >> guess;
        nb_essais += 1;
        if (guess < secret) {
            std::cout << "Trop Petit." << "\n";
        } else if (guess > secret) {
            std::cout << "Trop Grand." << "\n";
        } else {
            std::cout << "Bravo, vous avez gagne en " << nb_essais << " essais\n";
        }
        if (nb_essais == 7) {
            if (guess != secret) {
                std::cout << "Perdu le chiffre etait " << secret << "\n";
                break;
            }
        }
    } while (guess != secret);
    
    return 0;
}
