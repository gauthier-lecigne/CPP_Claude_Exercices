#include "Affichage.hpp"

#include <iostream>

void afficherGare(const Gare& g) {
    std::cout << "Gare " << g.getNom() << " : " << g.getNbQuais() << " quais" << std::endl;
}
