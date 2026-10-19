#include "Cercle.hpp"

Cercle::Cercle(double rayon) : rayon(rayon > 0 ? rayon : 1.0) {
}

// "override" ne se répète pas dans le .cpp.
std::string Cercle::nom() const { return "Cercle"; }
double Cercle::aire() const { return PI * rayon * rayon; }
double Cercle::perimetre() const { return 2 * PI * rayon; }
