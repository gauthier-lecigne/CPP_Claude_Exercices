/*
 * Exercice 4 — Petit programme à menu
 *
 * Écris un programme qui affiche un menu en boucle jusqu'à ce que
 * l'utilisateur choisisse "Quitter" :
 *
 *     === MENU ===
 *     1. PGCD de deux nombres
 *     2. Convertir des km en miles
 *     3. Afficher un rectangle d'etoiles
 *     0. Quitter
 *     Choix :
 *
 * Fonctions à écrire :
 *   void afficherMenu();
 *   int  lireChoix();                    // redemande tant que le choix n'est pas entre 0 et 3
 *   int  pgcd(int a, int b);             // algorithme d'Euclide (voir ci-dessous)
 *   double kmVersMiles(double km);       // 1 km = 0.621371 miles
 *   void afficherRectangle(int largeur, int hauteur);
 *
 * Algorithme d'Euclide :
 *   tant que b != 0 :
 *       reste = a % b
 *       a = b
 *       b = reste
 *   le PGCD est a
 *   (exemple : pgcd(48, 18) = 6)
 *
 * Le main doit rester court : il appelle les fonctions, il ne fait pas
 * les calculs lui-même.
 */

#include <iostream>

void afficherMenu() {
    std::cout << "=== MENU ===" << "\n";
    std::cout << "1. PGCD de deux nombres" << "\n";
    std::cout << "2. Convertir des km en miles" << "\n";
    std::cout << "3. Afficher un rectangle d'etoiles" << "\n";
    std::cout << "0. Quitter" << "\n";
}

int lireChoix() {
    int userChoice;
    afficherMenu();
    std::cout << "Choix : ";
    std::cin >> userChoice;
    while (userChoice < 0 || userChoice > 3) {
        afficherMenu();
        std::cout << "Choix : ";
        std::cin >> userChoice;
    }
    return userChoice;
}

int pgcd(int a, int b) {
    while(b != 0) {
        int reste;
        reste = a % b;
        a = b;
        b = reste;
    }
    return a;
}


double kmVersMiles(double km) {
    double miles = km * 0.621371;
    return miles;
}


void afficherRectangle(int largeur, int hauteur) {
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            std::cout << "*" << " ";
        }
        std::cout << "\n";
    }
}


int main() {
    int choix;
    do {
        choix = lireChoix();
        switch (choix)
        {
        case 0:
            break;
        
        case 1:
            int a;
            std::cout << "Nombre 1 : ";
            std::cin >> a;
            
            int b;
            std::cout << "Nombre 2 : ";
            std::cin >> b;
            
            std::cout << pgcd(a,b) << "\n";
            break;
            
        
        case 2:
            double km;
            std::cout << "Nombre de Km : ";
            std::cin >> km;
            
            std::cout << kmVersMiles(km) << "\n";
            break;
        
        case 3:
            int largeur;
            std::cout << "Largeur : ";
            std::cin >> largeur;
            
            int hauteur;
            std::cout << "Hauteur : ";
            std::cin >> hauteur;
            
            afficherRectangle(largeur, hauteur);
            std::cout << "\n";
            break;
            }
        } while (choix != 0);
}