#include <iostream>
#include <string>

int main() {
    std::string prenom;

    std::cout << "Ton prenom : ";
    std::cin >> prenom;

    std::cout << "Bonjour " << prenom << ", bienvenue en C++ !" << std::endl;
    return 0;
}
