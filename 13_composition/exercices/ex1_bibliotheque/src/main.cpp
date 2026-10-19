#include <iostream>
#include <string>

#include "Bibliotheque.hpp"
#include "Livre.hpp"

int reussis = 0;
int total = 0;

void verifier(const std::string& nom, bool condition) {
    total++;
    if (condition) reussis++;
    std::cout << (condition ? "[OK]    " : "[ECHEC] ") << nom << std::endl;
}

int main() {
    Bibliotheque biblio;
    biblio.ajouter(Livre("Le Petit Prince", "Saint-Exupery", 1943));
    biblio.ajouter(Livre("Les Miserables", "Victor Hugo", 1862));
    biblio.ajouter(Livre("Notre-Dame de Paris", "Victor Hugo", 1831));

    verifier("3 livres", biblio.getNbLivres() == 3);
    verifier("3 disponibles", biblio.getNbDisponibles() == 3);

    verifier("Lea emprunte Les Miserables", biblio.emprunter("Les Miserables", "Lea"));
    verifier("Hugo ne peut pas emprunter Les Miserables",
             !biblio.emprunter("Les Miserables", "Hugo"));
    verifier("emprunter un titre inconnu echoue", !biblio.emprunter("Inconnu", "Lea"));
    verifier("2 disponibles", biblio.getNbDisponibles() == 2);

    verifier("2 livres de Victor Hugo", biblio.livresDe("Victor Hugo").size() == 2);

    verifier("rendre Le Petit Prince (pas emprunte) echoue", !biblio.rendre("Le Petit Prince"));
    verifier("rendre Les Miserables", biblio.rendre("Les Miserables"));

    std::cout << reussis << "/" << total << " tests reussis\n\n";

    biblio.emprunter("Le Petit Prince", "Gauthier");
    biblio.afficher();
    return 0;
}
