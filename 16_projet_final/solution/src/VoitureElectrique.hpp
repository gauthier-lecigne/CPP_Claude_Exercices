#ifndef VOITURE_ELECTRIQUE_HPP
#define VOITURE_ELECTRIQUE_HPP

#include "TypesVehicule.hpp"

// Étape 5 : ajoutée sans modifier Vehicule, Place ni Parking.
// Elle EST une Voiture : elle hérite de getTailleMinimale() (place normale).
class VoitureElectrique : public Voiture {
public:
    using Voiture::Voiture;
    std::string getType() const override;
    double getTarifHoraire() const override;
    double getPlafond() const override;
};

#endif
