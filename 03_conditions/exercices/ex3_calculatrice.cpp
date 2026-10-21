/*
 * Exercice 3 — Calculatrice
 *
 * Demande une opération sous la forme : nombre operateur nombre
 * (par exemple "12 / 4") puis affiche le résultat.
 *
 * Opérateurs acceptés : + - * /
 *
 * Exemple :
 *     Calcul : 12 / 4
 *     Resultat : 3
 *
 *     Calcul : 5 / 0
 *     Erreur : division par zero
 *
 *     Calcul : 5 ? 2
 *     Erreur : operateur inconnu
 *
 * Contraintes :
 *   - utilise un switch sur l'opérateur ;
 *   - les nombres sont des double ;
 *   - gère la division par zéro.
 *
 * Indice : std::cin >> a >> op >> b; avec op de type char.
 */

#include <iostream>

int main() {
    double nombre1,nombre2;
    char opera;
    
    std::cout << "votre operation : ";
    std::cin >> nombre1 >> opera >> nombre2;
    
    switch (opera)
    {
    case '+':
        std::cout << nombre1 + nombre2 << "\n";
        break;
    case '-':
        std::cout << nombre1 - nombre2 << "\n";
        break;
    case '*':
        std::cout << nombre1 * nombre2 << "\n";
        break;
    case '/':
        if (nombre2 == 0) {
            std::cout << "Le diviseur ne peut pas etre 0" << "\n";
        } else {
            std::cout << nombre1 / nombre2 << "\n";
        }
        break;
    default:
        std::cout << "Operateur non reconnu" << "\n";
        break;
    }

    return 0;
}
