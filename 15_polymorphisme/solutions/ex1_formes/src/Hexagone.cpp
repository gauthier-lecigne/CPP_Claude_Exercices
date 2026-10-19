#include "Hexagone.hpp"

#include <cmath>

Hexagone::Hexagone(double cote) : cote(cote > 0 ? cote : 1.0) {
}

std::string Hexagone::nom() const { return "Hexagone"; }
double Hexagone::aire() const { return 3.0 * std::sqrt(3.0) / 2.0 * cote * cote; }
double Hexagone::perimetre() const { return 6 * cote; }
