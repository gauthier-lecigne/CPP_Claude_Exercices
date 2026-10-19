#include "Vehicule.hpp"

#include <sstream>

Vehicule::Vehicule(const std::string& marque, double vitesseMax)
    : marque(marque), vitesseMax(vitesseMax > 0 ? vitesseMax : 50.0), kilometrage(0.0) {
}

std::string Vehicule::getMarque() const { return marque; }
double Vehicule::getVitesseMax() const { return vitesseMax; }
double Vehicule::getKilometrage() const { return kilometrage; }

void Vehicule::rouler(double km) {
    if (km > 0) {
        kilometrage += km;
    }
}

double Vehicule::calculerTemps(double km, double vitesse) const {
    return km / vitesse;
}

double Vehicule::tempsTrajet(double km) const {
    return calculerTemps(km, vitesseMax);
}

std::string Vehicule::decrire() const {
    std::ostringstream s;
    s << marque << " (" << vitesseMax << " km/h, " << kilometrage << " km)";
    return s.str();
}
