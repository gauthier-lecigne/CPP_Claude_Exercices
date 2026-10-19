// ================================================================
//  Projet final : parking
//  Passe ETAPE à 2, 3, 4, 5 au fur et à mesure de ton avancement
//  (et décommente les lignes correspondantes du CMakeLists.txt).
// ================================================================
#define ETAPE 1

#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

#include "TaillePlace.hpp"
#include "TypesVehicule.hpp"
#include "Vehicule.hpp"
#if ETAPE >= 2
#include "Place.hpp"
#endif
#if ETAPE >= 3
#include "Parking.hpp"
#endif
#if ETAPE >= 5
#include "VoitureElectrique.hpp"
#endif

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

void testsEtape1() {
    std::cout << "--- Etape 1 : Vehicule ---\n";
    static_assert(std::is_abstract<Vehicule>::value, "Vehicule doit etre abstraite");
    static_assert(std::has_virtual_destructor<Vehicule>::value,
                  "Vehicule doit avoir un destructeur virtuel");

    Moto m("AA-111-AA");
    Voiture v("AB-123-CD");
    Camionnette c("CC-333-CC");

    verifier("decrire() = \"Voiture AB-123-CD\"", v.decrire() == "Voiture AB-123-CD");
    verifier("une moto demande une petite place", m.getTailleMinimale() == TaillePlace::Petite);
    verifier("une camionnette demande une grande place",
             c.getTailleMinimale() == TaillePlace::Grande);
    verifier("30 min gratuites", proche(v.calculerPrix(30), 0));
    verifier("31 min = 1 h entamee = 2 EUR", proche(v.calculerPrix(31), 2));
    verifier("61 min = 2 h = 4 EUR", proche(v.calculerPrix(61), 4));
    verifier("moto 2h15 = 3 h = 3 EUR", proche(m.calculerPrix(135), 3));
    verifier("voiture 15 h plafonnee a 25 EUR", proche(v.calculerPrix(15 * 60), 25));
    verifier("camionnette 15 h plafonnee a 40 EUR", proche(c.calculerPrix(15 * 60), 40));

    // Polymorphisme : via une référence Vehicule&, c'est le bon tarif qui s'applique.
    const Vehicule& ref = c;
    verifier("via Vehicule& : camionnette 2 h = 7 EUR", proche(ref.calculerPrix(120), 7));
}

#if ETAPE >= 2
void testsEtape2() {
    std::cout << "--- Etape 2 : Place ---\n";
    Moto m("AA-111-AA");
    Camionnette c("CC-333-CC");
    Place petite(1, TaillePlace::Petite);
    Place normale(2, TaillePlace::Normale);

    verifier("une place neuve est libre", petite.estLibre() && petite.getOccupant() == nullptr);
    verifier("une camionnette ne tient pas sur une petite place", !petite.peutAccueillir(c));
    verifier("une moto tient sur une place normale", normale.peutAccueillir(m));
    verifier("occuper avec la moto", normale.occuper(m, 45));
    verifier("l'occupant est la moto", normale.getOccupant() == &m);
    verifier("heure d'entree 45", normale.getHeureEntree() == 45);
    verifier("on ne peut pas occuper une place prise", !normale.occuper(m, 50));
    normale.liberer();
    verifier("liberer rend la place libre", normale.estLibre());
}
#endif

#if ETAPE >= 3
void testsEtape3() {
    std::cout << "--- Etape 3 : Parking ---\n";
    Parking p("Test");
    // Volontairement dans le désordre : le parking doit quand même choisir la plus petite place.
    p.ajouterPlaces(TaillePlace::Grande, 2);   // places 1, 2
    p.ajouterPlaces(TaillePlace::Petite, 2);   // places 3, 4
    p.ajouterPlaces(TaillePlace::Normale, 2);  // places 5, 6

    Moto m("AA-111-AA");
    Voiture v1("BB-222-BB"), v2("DD-444-DD"), v3("EE-555-EE");
    Camionnette c1("CC-333-CC"), c2("FF-666-FF");

    verifier("6 places libres", p.getNbPlacesLibres() == 6);
    verifier("la moto va sur une petite place", p.entrer(m, 0) == 3);
    verifier("la moto ne peut pas entrer deux fois", p.entrer(m, 10) == -1);
    verifier("v1 va sur une normale", p.entrer(v1, 30) == 5);
    verifier("v2 va sur l'autre normale", p.entrer(v2, 30) == 6);
    verifier("v3 deborde sur une grande", p.entrer(v3, 40) == 1);
    verifier("c1 prend la derniere grande", p.entrer(c1, 40) == 2);
    verifier("c2 est refusee (plus de grande place)", p.entrer(c2, 50) == -1);
    verifier("il reste 1 petite place", p.getNbPlacesLibres(TaillePlace::Petite) == 1);
    verifier("taux d'occupation 5/6", proche(p.getTauxOccupation(), 5.0 / 6.0));

    verifier("v1 sort apres 1h45 : 4 EUR", proche(p.sortir("BB-222-BB", 135), 4));
    verifier("sortir un vehicule absent : -1", proche(p.sortir("ZZ-999-ZZ", 140), -1));
    verifier("c2 peut maintenant entrer ? non : la place liberee est normale",
             p.entrer(c2, 140) == -1);
    verifier("recette = 4 EUR", proche(p.getRecette(), 4));
}
#endif

#if ETAPE >= 4
void scenarioEtape4() {
    std::cout << "\n--- Etape 4 : scenario ---\n";
    Parking p("Lille Europe");
    p.ajouterPlaces(TaillePlace::Petite, 2);
    p.ajouterPlaces(TaillePlace::Normale, 3);
    p.ajouterPlaces(TaillePlace::Grande, 1);

    // Le main POSSÈDE les véhicules ; le parking ne fait que les référencer.
    std::vector<std::unique_ptr<Vehicule>> vehicules;
    vehicules.push_back(std::make_unique<Moto>("AA-111-AA"));
    vehicules.push_back(std::make_unique<Voiture>("BB-222-BB"));
    vehicules.push_back(std::make_unique<Camionnette>("CC-333-CC"));
    vehicules.push_back(std::make_unique<Voiture>("DD-444-DD"));
#if ETAPE >= 5
    vehicules.push_back(std::make_unique<VoitureElectrique>("EV-777-EV"));
#endif

    int heure = 0;
    for (const auto& v : vehicules) {
        int place = p.entrer(*v, heure);
        std::cout << heure << " min : " << v->decrire()
                  << (place > 0 ? " -> place " + std::to_string(place) : " -> refuse") << "\n";
        heure += 30;
    }
    std::cout << "\n";
    p.afficherEtat(135);

    std::cout << "\nSortie de BB-222-BB a 02:15 : " << p.sortir("BB-222-BB", 135) << " EUR\n";
    std::cout << "Sortie de CC-333-CC a 10:00 : " << p.sortir("CC-333-CC", 600) << " EUR\n\n";
    p.afficherEtat(600);
}
#endif

#if ETAPE >= 5
void testsEtape5() {
    std::cout << "--- Etape 5 : VoitureElectrique ---\n";
    VoitureElectrique e("EV-777-EV");
    const Voiture& commeVoiture = e;   // une voiture électrique EST une voiture
    verifier("type", e.getType() == "Voiture electrique");
    verifier("place normale (heritee de Voiture)", e.getTailleMinimale() == TaillePlace::Normale);
    verifier("3 h = 3 EUR", proche(commeVoiture.calculerPrix(180), 3));
    verifier("15 h plafonnee a 12 EUR", proche(e.calculerPrix(15 * 60), 12));
}
#endif

int main() {
    testsEtape1();
#if ETAPE >= 2
    testsEtape2();
#endif
#if ETAPE >= 3
    testsEtape3();
#endif
#if ETAPE >= 5
    testsEtape5();
#endif
    std::cout << "\n" << reussis << "/" << total << " tests reussis (etape " << ETAPE << ")\n";
#if ETAPE >= 4
    scenarioEtape4();
#endif
    return 0;
}
