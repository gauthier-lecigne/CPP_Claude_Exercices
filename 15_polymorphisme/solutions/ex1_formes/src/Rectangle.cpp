#include "Rectangle.hpp"

Rectangle::Rectangle(double largeur, double hauteur)
    : largeur(largeur > 0 ? largeur : 1.0), hauteur(hauteur > 0 ? hauteur : 1.0) {
}

std::string Rectangle::nom() const { return "Rectangle"; }
double Rectangle::aire() const { return largeur * hauteur; }
double Rectangle::perimetre() const { return 2 * (largeur + hauteur); }
