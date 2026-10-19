/*
 * Exercice 1 — Convertisseur de température
 *
 * Demande une température en degrés Celsius (elle peut avoir une virgule)
 * et affiche sa valeur en Fahrenheit et en Kelvin.
 *
 *     F = C * 9 / 5 + 32
 *     K = C + 273.15
 *
 * Exemple :
 *     Temperature en Celsius : 21.5
 *     21.5 C = 70.7 F
 *     21.5 C = 294.65 K
 *
 * Question : que se passe-t-il si tu écris 9 / 5 avec des int ? Teste !
 */

#include <iostream>

int main() {
    double temp_cel;
    std::cout << "Votre temperature en degres Celsius : ";
    std::cin >> temp_cel;
    
    std::cout << temp_cel << " degres Celsius equivaut en Fahrenheit a : " << ((temp_cel * 9) / 5) + 32 <<" degres.\n";
    std::cout << temp_cel << " degres Celsius equivaut en Kelvin a : " << temp_cel + 273.15 <<" degres\n";

    return 0;
}
