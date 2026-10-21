/*
 * Exercice 4 — Caractères et codes ASCII
 *
 * Chaque caractère est stocké sous forme d'un nombre (son code ASCII) :
 * 'A' = 65, 'B' = 66, ..., 'a' = 97.
 *
 * 1. Demande une lettre MAJUSCULE à l'utilisateur.
 * 2. Affiche son code ASCII.
 * 3. Affiche la lettre suivante dans l'alphabet.
 * 4. Affiche la même lettre en minuscule (l'écart entre 'A' et 'a' est 32).
 *
 * Exemple :
 *     Une lettre majuscule : G
 *     Code ASCII : 71
 *     Lettre suivante : H
 *     En minuscule : g
 *
 * Indice : static_cast<int>(c) donne le code, static_cast<char>(n) donne
 *          le caractère.
 */

#include <iostream>

int main() {
    char Lettre;
    std::cout << "Veuillez entrer une lettre en majuscule : ";
    std::cin >> Lettre;
    
    std::cout << "Code ASCII : " << static_cast<int>(Lettre) << "\n";
    
    char LettreSuivante = Lettre + 1;
    std::cout << "Lettre suivante : " << static_cast<char>(LettreSuivante) << "\n";
    
    char minuscule = Lettre + 32;
    std::cout << "En minuscule : " << static_cast<char>(minuscule) << "\n";
    return 0;
}
