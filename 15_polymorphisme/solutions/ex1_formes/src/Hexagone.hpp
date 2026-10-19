#ifndef HEXAGONE_HPP
#define HEXAGONE_HPP

#include "Forme.hpp"

// Étape 2 : ajoutée sans modifier Forme, aireTotale, plusGrande ni la boucle d'affichage.
class Hexagone : public Forme {
public:
    explicit Hexagone(double cote);

    std::string nom() const override;
    double aire() const override;
    double perimetre() const override;

private:
    double cote;
};

#endif
