#include "Gare.hpp"

Gare::Gare(const string& nom, int nbQuais) {
    this->nom = nom;
    this->nbQuais = (nbQuais > 0) ? nbQuais : 1;
}

string Gare::getNom() {
    return nom;
}

int getNbQuais() const {
    return nbQuais;
}
