#include <iostream>
#include <string>

#include "Gare.hpp"
#include "Ligne.hpp"
#include "Reseau.hpp"

int reussis = 0;
int total = 0;

void verifier(const std::string& nom, bool condition) {
    total++;
    if (condition) reussis++;
    std::cout << (condition ? "[OK]    " : "[ECHEC] ") << nom << std::endl;
}

int main() {
    Reseau reseau;
    const Gare* lyon = reseau.ajouterGare("Lyon Part-Dieu", 4);
    reseau.ajouterGare("Macon", 2);
    reseau.ajouterGare("Dijon", 3);
    reseau.ajouterGare("Bourg-en-Bresse", 2);
    reseau.ajouterGare("Grenoble", 0);

    verifier("ajouterGare renvoie la gare", lyon != nullptr && lyon->getNom() == "Lyon Part-Dieu");
    verifier("une gare existante n'est pas dupliquee",
             reseau.ajouterGare("Lyon Part-Dieu", 10) == lyon);
    verifier("trouverGare(Macon)", reseau.trouverGare("Macon") != nullptr);
    verifier("trouverGare(Paris) = nullptr", reseau.trouverGare("Paris") == nullptr);
    verifier("Grenoble a au moins 1 quai", reseau.trouverGare("Grenoble")->getNbQuais() == 1);

    verifier("ligne A creee",
             reseau.ajouterLigne("A", {"Lyon Part-Dieu", "Macon", "Dijon"}));
    verifier("ligne B creee",
             reseau.ajouterLigne("B", {"Lyon Part-Dieu", "Bourg-en-Bresse", "Macon"}));
    verifier("ligne avec gare inconnue refusee",
             !reseau.ajouterLigne("C", {"Lyon Part-Dieu", "Paris"}));

    // Le pointeur obtenu au début doit rester valide malgré les ajouts suivants.
    verifier("le pointeur lyon est toujours valide", lyon->getNom() == "Lyon Part-Dieu");

    verifier("2 lignes passent par Macon", reseau.lignesPassantPar("Macon").size() == 2);

    std::cout << reussis << "/" << total << " tests reussis\n\n";
    reseau.afficher();
    return 0;
}
