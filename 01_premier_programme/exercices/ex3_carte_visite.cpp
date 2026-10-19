/*
 * Exercice 3 — Carte de visite
 *
 * Demande un prénom, un nom et une ville (un mot chacun), puis affiche
 * une "carte" encadrée comme ci-dessous :
 *
 *     +------------------------------+
 *     |  Prenom : Gauthier           |
 *     |  Nom    : Dupont             |
 *     |  Ville  : Lille              |
 *     +------------------------------+
 *
 * Ne cherche pas à aligner parfaitement le bord droit pour l'instant :
 * l'important est d'enchaîner plusieurs std::cout et d'utiliser \n ou std::endl.
 *
 * Bonus (plus difficile) : aligne le bord droit. Cherche "std::setw" et
 * "std::left" dans <iomanip>.
 */

#include <iostream>
#include <string>

int main() {
    // Demande Nom, Prénom, Ville
    std::string FirstName;
    std::cout << "Votre Prenom : ";
    std::cin >> FirstName;
    
    std::string LastName;
    std::cout << "Votre Nom : ";
    std::cin >> LastName;
    
    std::string CityName;
    std::cout << "Votre ville : ";
    std::cin >> CityName;
    
    
    std::cout << "+-------------------------------+\n";
    std::cout << "| Prenom  : " << FirstName << " |\n";
    std::cout << "| Nom     : " << LastName << "  |\n";
    std::cout << "| Ville   : " << CityName << "  |\n";
    std::cout << "+-------------------------------+";

    return 0;
}
