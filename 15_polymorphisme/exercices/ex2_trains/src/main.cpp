#include <algorithm>
#include <iomanip>
#include <iostream>
#include <memory>
#include <vector>

#include "Gare.hpp"
#include "Train.hpp"
#include "TypesTrain.hpp"
// Étape 2 : #include "TrainDeNuit.hpp"

// ================================================================
//  NE PAS MODIFIER cette fonction : c'est "la logique de simulation"
//  de la règle 5. Elle ne connaît que Train, jamais les types concrets.
// ================================================================
void simuler(std::vector<std::unique_ptr<Train>>& trains, int dureeTotale, int pas) {
    // Tableau trié par priorité décroissante (un appel virtuel par comparaison).
    std::sort(trains.begin(), trains.end(),
              [](const std::unique_ptr<Train>& a, const std::unique_ptr<Train>& b) {
                  return a->getPriorite() > b->getPriorite();
              });

    for (int t = 0; t <= dureeTotale; t += pas) {
        std::cout << "=== t = " << t << " min ===\n";
        for (const auto& train : trains) {
            std::cout << "[" << std::left << std::setw(4) << train->getType() << "] "
                      << std::setw(10) << train->getId() << " P" << train->getPriorite()
                      << "  " << train->getPosition() << "\n";
        }
        std::cout << "\n";
        for (auto& train : trains) {
            train->avancer(pas);
        }
    }
}
// ================================================================

int main() {
    Gare lyon("Lyon Part-Dieu", 4);
    Gare macon("Macon", 2);
    Gare dijon("Dijon", 3);
    std::vector<const Gare*> trajet = {&lyon, &macon, &dijon};

    std::vector<std::unique_ptr<Train>> trains;
    trains.push_back(std::make_unique<Fret>("FRET 42", trajet));
    trains.push_back(std::make_unique<TGV>("TGV 6601", trajet));
    trains.push_back(std::make_unique<TER>("TER 8812", trajet));
    // Étape 2 : ajoute ton train de nuit ici (une seule ligne).

    simuler(trains, 90, 15);
    return 0;
}
