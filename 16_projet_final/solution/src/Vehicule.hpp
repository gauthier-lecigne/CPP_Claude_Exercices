#ifndef VEHICULE_HPP
#define VEHICULE_HPP

#include <string>

#include "TaillePlace.hpp"

class Vehicule {
public:
    explicit Vehicule(const std::string& immatriculation);
    virtual ~Vehicule() = default;

    std::string getImmatriculation() const;
    std::string decrire() const;

    // Méthode modèle : la règle de calcul est la même pour tous les véhicules,
    // seuls le tarif et le plafond changent (méthodes virtuelles).
    double calculerPrix(int dureeMinutes) const;

    virtual std::string getType() const = 0;
    virtual double getTarifHoraire() const = 0;
    virtual TaillePlace getTailleMinimale() const = 0;
    virtual double getPlafond() const;

private:
    static constexpr int MINUTES_GRATUITES = 30;
    static constexpr double PLAFOND_PAR_DEFAUT = 25.0;

    std::string immatriculation;
};

#endif
