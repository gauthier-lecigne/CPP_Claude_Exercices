#include <iomanip>   // std::setw, std::left
#include <iostream>
#include <string>

int main() {
    std::string prenom, nom, ville;

    std::cout << "Prenom : ";
    std::cin >> prenom;
    std::cout << "Nom : ";
    std::cin >> nom;
    std::cout << "Ville : ";
    std::cin >> ville;

    // setw(20) réserve 20 caractères pour la valeur suivante,
    // left la colle à gauche et complète avec des espaces.
    std::cout << "+------------------------------+\n";
    std::cout << "|  Prenom : " << std::left << std::setw(19) << prenom << "|\n";
    std::cout << "|  Nom    : " << std::left << std::setw(19) << nom << "|\n";
    std::cout << "|  Ville  : " << std::left << std::setw(19) << ville << "|\n";
    std::cout << "+------------------------------+\n";
    return 0;
}
