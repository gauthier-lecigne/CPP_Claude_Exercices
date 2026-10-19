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

int main() {
    // TODO

    return 0;
}
