#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Gare {
    std::string nom;
    int quais;
};

void afficherGare(const Gare* g) {
    if (g == nullptr) {
        std::cout << "Gare inconnue" << std::endl;
        return;
    }
    std::cout << g->nom << " (" << g->quais << " quais)" << std::endl;
}

Gare* trouverGare(const std::vector<std::unique_ptr<Gare>>& gares,
                  const std::string& nom) {
    for (const auto& g : gares) {
        if (g->nom == nom) {
            return g.get();   // pointeur "brut" : on prête la gare, on ne la donne pas
        }
    }
    return nullptr;
}

int main() {
    // 1.
    std::unique_ptr<Gare> maGare = std::make_unique<Gare>(Gare{"Lyon Part-Dieu", 4});
    std::cout << maGare->nom << " : " << maGare->quais << " quais" << std::endl;

    // 2.
    afficherGare(maGare.get());
    afficherGare(nullptr);

    // 3.
    std::vector<std::unique_ptr<Gare>> gares;
    gares.push_back(std::make_unique<Gare>(Gare{"Lyon Part-Dieu", 4}));
    gares.push_back(std::make_unique<Gare>(Gare{"Macon", 2}));
    gares.push_back(std::make_unique<Gare>(Gare{"Dijon", 3}));

    // "for (auto g : gares)" essaierait de COPIER chaque unique_ptr,
    // ce qui est interdit (il ne peut y avoir qu'un seul propriétaire).
    for (const auto& g : gares) {
        afficherGare(g.get());
    }

    // 4.
    afficherGare(trouverGare(gares, "Macon"));
    afficherGare(trouverGare(gares, "Paris"));

    return 0;   // toutes les gares sont libérées automatiquement ici
}
