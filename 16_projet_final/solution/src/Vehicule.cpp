#include "Vehicule.hpp"

#include <algorithm>

Vehicule::Vehicule(const std::string& immatriculation) : immatriculation(immatriculation) {
}

std::string Vehicule::getImmatriculation() const {
    return immatriculation;
}

std::string Vehicule::decrire() const {
    return getType() + " " + immatriculation;
}

double Vehicule::getPlafond() const {
    return PLAFOND_PAR_DEFAUT;
}

double Vehicule::calculerPrix(int dureeMinutes) const {
    if (dureeMinutes <= MINUTES_GRATUITES) {
        return 0.0;
    }
    // Heures entamées, en arithmétique entière : (d + 59) / 60 arrondit au-dessus.
    int heures = (dureeMinutes + 59) / 60;
    double prix = heures * getTarifHoraire();
    return std::min(prix, getPlafond());
}
