#ifndef VOITURE_HPP
#define VOITURE_HPP

#include <string>

#include "Vehicule.hpp"

class Voiture : public Vehicule {
public:
    Voiture(const std::string& marque, double vitesseMax, int nbPlaces);

    int getNbPlaces() const;
    std::string decrire() const;

private:
    int nbPlaces;
};

#endif
