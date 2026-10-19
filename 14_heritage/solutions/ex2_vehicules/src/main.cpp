#include <cmath>
#include <iostream>
#include <string>
#include <vector>

#include "Camion.hpp"
#include "Vehicule.hpp"
#include "Voiture.hpp"

int reussis = 0;
int total = 0;

void verifier(const std::string& nom, bool condition) {
    total++;
    if (condition) reussis++;
    std::cout << (condition ? "[OK]    " : "[ECHEC] ") << nom << std::endl;
}

bool proche(double a, double b) {
    return std::abs(a - b) < 0.001;
}

int main() {
    Voiture v("Renault", 130, 5);
    v.rouler(1200);
    v.rouler(-50);
    verifier("kilometrage 1200", proche(v.getKilometrage(), 1200));
    verifier("decrire voiture",
             v.decrire() == "Voiture Renault (130 km/h, 1200 km), 5 places");
    verifier("temps voiture 260 km = 2 h", proche(v.tempsTrajet(260), 2.0));

    Camion c("Volvo", 90, 20);
    verifier("charger 12 t", c.charger(12));
    verifier("charger 10 t de plus refuse", !c.charger(10));
    verifier("charge = 12", proche(c.getCharge(), 12));
    verifier("decrire camion", c.decrire() == "Camion Volvo (90 km/h, 0 km), charge 12/20 t");
    verifier("camion charge : 63 km = 1 h", proche(c.tempsTrajet(63), 1.0));
    c.decharger();
    verifier("camion vide : 90 km = 1 h", proche(c.tempsTrajet(90), 1.0));

    std::cout << reussis << "/" << total << " tests reussis\n\n";

    c.charger(15);
    std::vector<Vehicule*> garage = {&v, &c};
    std::cout << "--- Via des Vehicule* ---\n";
    for (Vehicule* veh : garage) {
        std::cout << veh->decrire() << " : 450 km en " << veh->tempsTrajet(450) << " h\n";
    }
    std::cout << "--- Appel direct ---\n";
    std::cout << c.decrire() << " : 450 km en " << c.tempsTrajet(450) << " h\n";
    return 0;
}
