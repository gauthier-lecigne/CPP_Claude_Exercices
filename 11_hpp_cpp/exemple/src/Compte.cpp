#include "Compte.hpp"

Compte::Compte(const std::string& titulaire, double soldeInitial) {
    this->titulaire = titulaire;
    solde = (soldeInitial > 0) ? soldeInitial : 0.0;
}

void Compte::deposer(double montant) {
    if (montant > 0) {
        solde += montant;
    }
}

bool Compte::retirer(double montant) {
    if (montant <= 0 || montant > solde) {
        return false;
    }
    solde -= montant;
    return true;
}

double Compte::getSolde() const {
    return solde;
}

std::string Compte::getTitulaire() const {
    return titulaire;
}
