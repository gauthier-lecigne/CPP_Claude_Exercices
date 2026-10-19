// Décommente la ligne suivante quand tu as fait le bonus (opérateurs).
// #define BONUS_OPERATEURS

#include <iostream>
#include <string>

#include "Fraction.hpp"

int reussis = 0;
int total = 0;

void verifier(const std::string& nom, bool condition) {
    total++;
    if (condition) reussis++;
    std::cout << (condition ? "[OK]    " : "[ECHEC] ") << nom << std::endl;
}

int main() {
    Fraction zero;
    verifier("Fraction() = 0", zero.toString() == "0");

    Fraction f(6, -8);
    verifier("6/-8 simplifiee en -3/4", f.getNumerateur() == -3 && f.getDenominateur() == 4);
    verifier("toString(-3/4) = \"-3/4\"", f.toString() == "-3/4");

    verifier("Fraction(5) = 5", Fraction(5).toString() == "5");
    verifier("Fraction(0, 7) = 0/1", Fraction(0, 7).getDenominateur() == 1);
    verifier("denominateur 0 remplace par 1", Fraction(3, 0).toString() == "3");

    Fraction a(1, 2), b(1, 3);
    verifier("1/2 + 1/3 = 5/6", a.additionner(b).toString() == "5/6");
    verifier("2/3 * 3/4 = 1/2", Fraction(2, 3).multiplier(Fraction(3, 4)).toString() == "1/2");
    verifier("inverse(-3/4) = -4/3", f.inverse().toString() == "-4/3");
    verifier("1/2 egale 2/4", a.egale(Fraction(2, 4)));
    verifier("3/4 vaut 0.75", Fraction(3, 4).versDouble() == 0.75);

    // L'objet d'origine ne doit pas être modifié par les opérations.
    verifier("a n'est pas modifie par additionner", a.toString() == "1/2");

#ifdef BONUS_OPERATEURS
    verifier("operator+ : 1/2 + 1/3 = 5/6", (a + b) == Fraction(5, 6));
    verifier("operator* : (1/2 + 1/3) * 6/5 = 1", ((a + b) * Fraction(6, 5)) == Fraction(1));
    std::cout << "operator<< : " << a << " + " << b << " = " << a + b << std::endl;
#endif

    std::cout << reussis << "/" << total << " tests reussis" << std::endl;
    return 0;
}
