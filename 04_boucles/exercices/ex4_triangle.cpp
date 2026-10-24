/*
 * Exercice 4 — Dessins avec des étoiles
 *
 * Demande une hauteur h (entre 1 et 20, redemande si invalide avec un
 * do...while), puis affiche ces trois figures :
 *
 * a) Triangle rectangle (h = 4) :
 *     *
 *     **
 *     ***
 *     ****
 *
 * b) Triangle inversé :
 *     ****
 *     ***
 *     **
 *     *
 *
 * c) Pyramide centrée :
 *        *
 *       ***
 *      *****
 *     *******
 *
 * Indice pour c) : à la ligne i (de 1 à h), il y a (h - i) espaces
 *                  puis (2 * i - 1) étoiles.
 */

#include <iostream>

int main() {
    int hauteur;
    do {
        std::cout << "Hauteur (1-20) : ";
        std::cin >> hauteur;
    } while (hauteur < 1 || hauteur > 20);
    
    
    //triangle normal
    for (int i = 1; i <= hauteur; ++i) {
        for (int j = 1; j <= i; ++j) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    
    std::cout << "\n";
    
    //triangle inversee
    for (int i = hauteur; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    
    std::cout << "\n";
    
    
    //Pyramide centrée
    for (int i = 1; i <= hauteur; i++) {
        int ecart = hauteur - i;
        for (int j = 1; j <= ecart; j++) {
            std::cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    
    std::cout << "\n";
    
    //Pyramide centrée inversée
    for (int i = hauteur; i >= 1; i--) {
        int ecart = hauteur - i;
        for (int j = 1; j <= ecart; j++) {
            std::cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}