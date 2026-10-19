#include <iostream>

#include "Compte.hpp"

int main() {
    Compte c("Gauthier", 100);
    c.deposer(50);

    if (!c.retirer(1000)) {
        std::cout << "Retrait refuse" << std::endl;
    }

    std::cout << c.getTitulaire() << " : " << c.getSolde() << " EUR" << std::endl;
    return 0;
}
