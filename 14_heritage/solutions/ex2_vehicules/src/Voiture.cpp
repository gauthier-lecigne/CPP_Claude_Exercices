#include "Voiture.hpp"

Voiture::Voiture(const std::string& marque, double vitesseMax, int nbPlaces)
    : Vehicule(marque, vitesseMax), nbPlaces(nbPlaces > 0 ? nbPlaces : 1) {
}

int Voiture::getNbPlaces() const {
    return nbPlaces;
}

std::string Voiture::decrire() const {
    return "Voiture " + Vehicule::decrire() + ", " + std::to_string(nbPlaces) + " places";
}
