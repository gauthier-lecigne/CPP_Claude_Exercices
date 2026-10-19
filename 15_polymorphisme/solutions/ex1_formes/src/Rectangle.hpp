#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Forme.hpp"

class Rectangle : public Forme {
public:
    Rectangle(double largeur, double hauteur);

    std::string nom() const override;
    double aire() const override;
    double perimetre() const override;

private:
    double largeur;
    double hauteur;
};

#endif
