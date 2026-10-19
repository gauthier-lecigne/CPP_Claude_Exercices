#ifndef TYPES_VEHICULE_HPP
#define TYPES_VEHICULE_HPP

#include "Vehicule.hpp"

class Moto : public Vehicule {
public:
    using Vehicule::Vehicule;
    std::string getType() const override;
    double getTarifHoraire() const override;
    TaillePlace getTailleMinimale() const override;
};

class Voiture : public Vehicule {
public:
    using Vehicule::Vehicule;
    std::string getType() const override;
    double getTarifHoraire() const override;
    TaillePlace getTailleMinimale() const override;
};

class Camionnette : public Vehicule {
public:
    using Vehicule::Vehicule;
    std::string getType() const override;
    double getTarifHoraire() const override;
    TaillePlace getTailleMinimale() const override;
    double getPlafond() const override;
};

#endif
