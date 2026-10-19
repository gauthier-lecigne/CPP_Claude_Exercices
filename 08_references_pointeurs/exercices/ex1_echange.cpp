/*
 * Exercice 1 — Échanger deux variables
 *
 * 1. Écris  void echangerValeur(int a, int b);
 *    qui échange a et b (à l'intérieur de la fonction).
 *    Appelle-la depuis le main et affiche les variables avant/après.
 *    Que constates-tu ? Explique pourquoi en commentaire.
 *
 * 2. Écris  void echangerReference(int& a, int& b);
 *    et refais le test.
 *
 * 3. Écris  void echangerPointeur(int* a, int* b);
 *    Comment l'appelle-t-on depuis le main ? (Indice : &x)
 *
 * Sortie attendue :
 *     Avant : x = 3, y = 8
 *     Apres echangerValeur : x = 3, y = 8
 *     Apres echangerReference : x = 8, y = 3
 *     Apres echangerPointeur : x = 3, y = 8
 */

#include <iostream>

int main() {
    int x = 3;
    int y = 8;
    std::cout << "Avant : x = " << x << ", y = " << y << std::endl;

    // TODO

    return 0;
}
