#include <algorithm>
#include <cmath>
#include <iostream>
#include <memory>
#include <string>
#include <type_traits>
#include <vector>

#include "Carre.hpp"
#include "Cercle.hpp"
#include "Forme.hpp"
#include "Hexagone.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"

// Vérification à la compilation : Forme DOIT être abstraite.
static_assert(std::is_abstract<Forme>::value, "Forme doit etre abstraite");

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

double aireTotale(const std::vector<std::unique_ptr<Forme>>& formes) {
    double somme = 0.0;
    for (const auto& f : formes) {
        somme += f->aire();   // appel virtuel : la bonne formule pour chaque forme
    }
    return somme;
}

const Forme* plusGrande(const std::vector<std::unique_ptr<Forme>>& formes) {
    const Forme* best = nullptr;
    for (const auto& f : formes) {
        if (best == nullptr || f->aire() > best->aire()) {
            best = f.get();
        }
    }
    return best;
}

int main() {
    std::vector<std::unique_ptr<Forme>> formes;
    formes.push_back(std::make_unique<Cercle>(1.0));
    formes.push_back(std::make_unique<Rectangle>(4.0, 2.5));
    formes.push_back(std::make_unique<Triangle>(3.0, 4.0, 5.0));
    formes.push_back(std::make_unique<Carre>(3.0));
    formes.push_back(std::make_unique<Triangle>(1.0, 2.0, 10.0));   // invalide -> 1, 1, 1
    // Étape 2 : une seule ligne ajoutée ici. Rien d'autre n'a changé dans le programme.
    formes.push_back(std::make_unique<Hexagone>(1.0));

    verifier("aire du cercle de rayon 1 = pi", proche(formes[0]->aire(), 3.14159));
    verifier("aire du rectangle 4 x 2.5 = 10", proche(formes[1]->aire(), 10));
    verifier("aire du triangle 3-4-5 = 6", proche(formes[2]->aire(), 6));
    verifier("perimetre du triangle 3-4-5 = 12", proche(formes[2]->perimetre(), 12));
    verifier("un Carre s'appelle \"Carre\"", formes[3]->nom() == "Carre");
    verifier("aire du carre de cote 3 = 9 (heritee)", proche(formes[3]->aire(), 9));
    verifier("triangle invalide remplace par 1-1-1", proche(formes[4]->perimetre(), 3));
    verifier("plusGrande est le rectangle", plusGrande(formes) == formes[1].get());

    std::cout << reussis << "/" << total << " tests reussis\n\n";

    // Tri par aire décroissante. La fonction de comparaison reçoit des unique_ptr.
    std::sort(formes.begin(), formes.end(),
              [](const std::unique_ptr<Forme>& a, const std::unique_ptr<Forme>& b) {
                  return a->aire() > b->aire();
              });

    for (const auto& f : formes) {
        std::cout << f->decrire() << "\n";
    }
    std::cout << "Aire totale : " << aireTotale(formes) << std::endl;
    return 0;
}
