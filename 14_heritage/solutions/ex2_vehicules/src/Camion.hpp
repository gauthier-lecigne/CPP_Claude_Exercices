#ifndef CAMION_HPP
#define CAMION_HPP

#include <string>

#include "Vehicule.hpp"

class Camion : public Vehicule {
public:
    Camion(const std::string& marque, double vitesseMax, double chargeMax);

    bool charger(double tonnes);
    void decharger();
    double getCharge() const;

    double tempsTrajet(double km) const;   // masque celle de Vehicule (pas virtual)
    std::string decrire() const;

private:
    static constexpr double SEUIL_CHARGE = 0.5;      // au-delà de 50 %...
    static constexpr double FACTEUR_LENT = 0.7;      // ...on roule à 70 %

    double chargeMax;
    double charge;
};

#endif
