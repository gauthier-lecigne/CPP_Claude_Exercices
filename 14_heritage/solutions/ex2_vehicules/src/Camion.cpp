#include "Camion.hpp"

#include <sstream>

Camion::Camion(const std::string& marque, double vitesseMax, double chargeMax)
    : Vehicule(marque, vitesseMax), chargeMax(chargeMax > 0 ? chargeMax : 1.0), charge(0.0) {
}

bool Camion::charger(double tonnes) {
    if (tonnes <= 0 || charge + tonnes > chargeMax) {
        return false;
    }
    charge += tonnes;
    return true;
}

void Camion::decharger() {
    charge = 0.0;
}

double Camion::getCharge() const {
    return charge;
}

double Camion::tempsTrajet(double km) const {
    double vitesse = getVitesseMax();   // vitesseMax est private dans Vehicule : on passe par le getter
    if (charge > chargeMax * SEUIL_CHARGE) {
        vitesse *= FACTEUR_LENT;
    }
    return calculerTemps(km, vitesse);  // méthode protected de la mère : accessible ici
}

std::string Camion::decrire() const {
    std::ostringstream s;
    s << "Camion " << Vehicule::decrire() << ", charge " << charge << "/" << chargeMax << " t";
    return s.str();
}
