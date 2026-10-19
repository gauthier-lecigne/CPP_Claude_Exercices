#include "Ligne.hpp"

#include "Gare.hpp"   // ici on appelle getNom() : il faut la définition complète

Ligne::Ligne(const std::string& nom) : nom(nom) {
}

std::string Ligne::getNom() const {
    return nom;
}

void Ligne::ajouterGare(const Gare* gare) {
    if (gare == nullptr) {
        return;
    }
    if (!gares.empty() && gares.back() == gare) {
        return;   // même gare deux fois de suite : pas de segment de longueur nulle
    }
    gares.push_back(gare);
}

bool Ligne::dessert(const std::string& nomGare) const {
    for (const Gare* g : gares) {
        if (g->getNom() == nomGare) {
            return true;
        }
    }
    return false;
}

std::size_t Ligne::getNbGares() const {
    return gares.size();
}

const Gare* Ligne::getTerminus() const {
    if (gares.empty()) {
        return nullptr;
    }
    return gares.back();
}

std::string Ligne::toString() const {
    std::string s = "Ligne " + nom + " : ";
    for (std::size_t i = 0; i < gares.size(); i++) {
        if (i > 0) {
            s += " -> ";
        }
        s += gares[i]->getNom();
    }
    return s;
}
