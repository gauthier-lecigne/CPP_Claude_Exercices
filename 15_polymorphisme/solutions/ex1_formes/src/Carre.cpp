#include "Carre.hpp"

Carre::Carre(double cote) : Rectangle(cote, cote) {
}

std::string Carre::nom() const {
    return "Carre";
}
