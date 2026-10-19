#include "Triangle.hpp"

#include <cmath>

bool Triangle::estValide(double a, double b, double c) {
    return a > 0 && b > 0 && c > 0 && a < b + c && b < a + c && c < a + b;
}

Triangle::Triangle(double a, double b, double c)
    : a(estValide(a, b, c) ? a : 1.0),
      b(estValide(a, b, c) ? b : 1.0),
      c(estValide(a, b, c) ? c : 1.0) {
    // Dans la liste d'initialisation, "a", "b", "c" désignent les PARAMÈTRES :
    // les paramètres masquent les attributs de même nom.
}

std::string Triangle::nom() const { return "Triangle"; }

double Triangle::perimetre() const {
    return a + b + c;
}

double Triangle::aire() const {
    double s = perimetre() / 2;   // formule de Héron
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}
