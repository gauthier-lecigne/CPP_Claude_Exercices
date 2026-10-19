#include "Reseau.hpp"

#include <iostream>

const Gare* Reseau::ajouterGare(const std::string& nom, int nbQuais) {
    const Gare* existante = trouverGare(nom);
    if (existante != nullptr) {
        return existante;
    }
    gares.push_back(std::make_unique<Gare>(nom, nbQuais));
    return gares.back().get();
}

const Gare* Reseau::trouverGare(const std::string& nom) const {
    for (const auto& g : gares) {
        if (g->getNom() == nom) {
            return g.get();
        }
    }
    return nullptr;
}

bool Reseau::ajouterLigne(const std::string& nom, const std::vector<std::string>& nomsGares) {
    // On vérifie TOUT avant de créer quoi que ce soit : pas de ligne à moitié construite.
    std::vector<const Gare*> arrets;
    for (const std::string& n : nomsGares) {
        const Gare* g = trouverGare(n);
        if (g == nullptr) {
            return false;
        }
        arrets.push_back(g);
    }

    Ligne ligne(nom);
    for (const Gare* g : arrets) {
        ligne.ajouterGare(g);
    }
    lignes.push_back(ligne);
    return true;
}

std::vector<std::string> Reseau::lignesPassantPar(const std::string& nomGare) const {
    std::vector<std::string> resultat;
    for (const Ligne& l : lignes) {
        if (l.dessert(nomGare)) {
            resultat.push_back(l.getNom());
        }
    }
    return resultat;
}

void Reseau::afficher() const {
    std::cout << "Gares :\n";
    for (const auto& g : gares) {
        std::cout << "  - " << g->getNom() << " (" << g->getNbQuais() << " quais)\n";
    }
    std::cout << "Lignes :\n";
    for (const Ligne& l : lignes) {
        std::cout << "  " << l.toString() << "\n";
    }
}
