#include "Gare.hpp"

Gare::Gare(const std::string& nom, int nbQuais)
    : nom(nom), nbQuais(nbQuais >= 1 ? nbQuais : 1) {
}

std::string Gare::getNom() const {
    return nom;
}

int Gare::getNbQuais() const {
    return nbQuais;
}
