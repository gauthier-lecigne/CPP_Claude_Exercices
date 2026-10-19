#include "Livre.hpp"

Livre::Livre(const std::string& titre, const std::string& auteur, int annee)
    : titre(titre), auteur(auteur), annee(annee) {
    // emprunteur est une std::string : elle est vide par défaut.
}

std::string Livre::getTitre() const { return titre; }
std::string Livre::getAuteur() const { return auteur; }
int Livre::getAnnee() const { return annee; }
bool Livre::estDisponible() const { return emprunteur.empty(); }
std::string Livre::getEmprunteur() const { return emprunteur; }

bool Livre::emprunter(const std::string& personne) {
    if (!estDisponible() || personne.empty()) {
        return false;
    }
    emprunteur = personne;
    return true;
}

bool Livre::rendre() {
    if (estDisponible()) {
        return false;
    }
    emprunteur.clear();
    return true;
}

std::string Livre::toString() const {
    std::string etat = estDisponible() ? "disponible" : "emprunte par " + emprunteur;
    return titre + " - " + auteur + " (" + std::to_string(annee) + ") [" + etat + "]";
}
