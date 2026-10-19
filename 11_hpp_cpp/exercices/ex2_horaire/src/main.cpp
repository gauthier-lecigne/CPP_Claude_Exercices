#include <iostream>
#include <string>

#include "Horaire.hpp"

int reussis = 0;
int total = 0;

void verifier(const std::string& nom, bool condition) {
    total++;
    if (condition) {
        reussis++;
    }
    std::cout << (condition ? "[OK]    " : "[ECHEC] ") << nom << std::endl;
}

int main() {
    Horaire h(14, 5);
    verifier("Horaire(14, 5) -> 14:05", h.toString() == "14:05");
    verifier("getHeures = 14, getMinutes = 5", h.getHeures() == 14 && h.getMinutes() == 5);

    Horaire grand(25, 70);
    verifier("Horaire(25, 70) -> 02:10", grand.toString() == "02:10");

    Horaire tard(23, 30);
    tard.ajouterMinutes(45);
    verifier("23:30 + 45 min -> 00:15", tard.toString() == "00:15");

    Horaire tot(0, 10);
    tot.ajouterMinutes(-30);
    verifier("00:10 - 30 min -> 23:40", tot.toString() == "23:40");

    Horaire a(8, 0), b(9, 30);
    verifier("08:00 -> 09:30 = 90 min", a.minutesJusqua(b) == 90);
    verifier("23:50 -> 00:10 = 20 min",
             Horaire(23, 50).minutesJusqua(Horaire(0, 10)) == 20);
    verifier("08:00 est avant 09:30", a.estAvant(b));
    verifier("09:30 n'est pas avant 08:00", !b.estAvant(a));
    verifier("Horaire(7, 3) -> 07:03", Horaire(7, 3).toString() == "07:03");

    std::cout << reussis << "/" << total << " tests reussis" << std::endl;
    return 0;
}
