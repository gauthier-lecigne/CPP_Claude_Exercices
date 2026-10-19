#include <iostream>

#include "Billet.hpp"

void afficherBillet(const Billet& b) {
    b.afficher();
}

int main() {
    std::cout << "Debut : " << Billet::getNbBilletsActifs() << " billet(s)\n\n";

    Billet b1("Gauthier", "Lyon -> Dijon", 45);
    afficherBillet(b1);

    {
        std::cout << "\n-- entree dans le bloc --\n";
        Billet b2("Lea", "Lyon -> Macon", 20);
        Billet b3("Hugo", "Macon -> Dijon", -10);
        b2.appliquerReductionJeune();
        afficherBillet(b2);
        afficherBillet(b3);
        std::cout << "Dans le bloc : " << Billet::getNbBilletsActifs() << " billet(s)\n";
        std::cout << "-- sortie du bloc --\n";
    }

    std::cout << "\nApres le bloc : " << Billet::getNbBilletsActifs() << " billet(s)\n";

    Billet b4("Ines", "Dijon -> Lyon", 45);
    afficherBillet(b4);

    std::cout << "\nFin du main : " << Billet::getNbBilletsActifs() << " billet(s)\n";
    return 0;
}
