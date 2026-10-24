/*
 * Exercice 5 — FizzBuzz (grand classique d'entretien)
 *
 * Affiche les nombres de 1 à 100, mais :
 *   - pour les multiples de 3, affiche "Fizz" à la place du nombre ;
 *   - pour les multiples de 5, affiche "Buzz" ;
 *   - pour les multiples de 3 ET de 5, affiche "FizzBuzz".
 *
 * Début attendu :
 *     1
 *     2
 *     Fizz
 *     4
 *     Buzz
 *     Fizz
 *     7
 *     ...
 *     14
 *     FizzBuzz
 *
 * Piège : dans quel ordre faut-il tester les conditions ?
 */

#include <iostream>

int main() {
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0 && i % 5 != 0) {
            std::cout << "Fizz" << "\n";
        } else if (i % 3 != 0 && i % 5 == 0) {
            std::cout << "Buzz" << "\n";
        } else if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "FizzBuzz" << "\n";
        } else {
            std::cout << i << "\n";
        }
    }
    
    std::cout << "\n";
    
    // Version sans le && partout (en gerant l'ordre des conditions
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "FizzBuzz" << "\n";
        } else if (i % 3 == 0) {
            std::cout << "Fizz" << "\n";
        } else if (i % 5 == 0) {
            std::cout << "Buzz" << "\n";
        } else {
            std::cout << i << "\n";
        }
    }
    
    std::cout << "n";
    
    // Version plus simple
    for (int i = 1; i <= 100; i++) {
        if (i % 15 == 0) {
            std::cout << "FizzBuzz" << "\n";
        } else if (i % 3 == 0) {
            std::cout << "Fizz" << "\n";
        } else if (i % 5 == 0) {
            std::cout << "Buzz" << "\n";
        } else {
            std::cout << i << "\n";
        }
    }

    return 0;
}
