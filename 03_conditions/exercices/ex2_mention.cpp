/*
 * Exercice 2 — Mention au bac
 *
 * Demande une note sur 20 (avec décimales possibles) et affiche la mention :
 *
 *     note < 0 ou note > 20  ->  "Note invalide"
 *     note < 10              ->  "Ajourne"
 *     10 <= note < 12        ->  "Admis"
 *     12 <= note < 14        ->  "Assez bien"
 *     14 <= note < 16        ->  "Bien"
 *     note >= 16             ->  "Tres bien"
 *
 * Exemple :
 *     Note : 14.5
 *     Mention : Bien
 *
 * Défi : écris la chaîne de if/else if de façon à ne jamais tester
 *        deux fois la même borne.
 */

#include <iostream>

int main() {
    double note;
    std::cout << "Votre note : ";
    std::cin >> note;
    
    if (note < 0 || note > 20) {
        std::cout << "Note invalide" << "\n";
    } else if (note < 10) {
        std::cout << "Ajourne" << "\n";
    } else if (note < 12) {
        std::cout << "Admis" << "\n";
    } else if (note < 14) {
        std::cout << "Assez bien" << "\n";
    } else if (note < 16) {
        std::cout << "Bien" << "\n";
    } else {
        std::cout << "Tres bien" << "\n";
    }

    return 0;
}
