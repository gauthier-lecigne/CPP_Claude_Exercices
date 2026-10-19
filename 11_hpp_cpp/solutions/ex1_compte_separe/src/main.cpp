#include <iostream>

#include "CompteBancaire.hpp"

int main() {
    CompteBancaire a("Gauthier", 100);
    CompteBancaire b("Lea", -50);
    a.afficher();
    b.afficher();

    if (!a.retirer(500)) {
        std::cout << "Retrait de 500 refuse" << std::endl;
    }
    a.deposer(50);
    a.virerVers(b, 30);
    a.afficher();
    b.afficher();

    if (!b.virerVers(a, 1000)) {
        std::cout << "Virement refuse" << std::endl;
    }
    return 0;
}
