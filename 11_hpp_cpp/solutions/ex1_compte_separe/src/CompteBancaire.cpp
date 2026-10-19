#include "CompteBancaire.hpp"

#include <iostream>   // utilisé seulement par afficher() : il reste dans le .cpp

CompteBancaire::CompteBancaire(const std::string& titulaire, double soldeInitial) {
    this->titulaire = titulaire;
    solde = (soldeInitial > 0) ? soldeInitial : 0.0;
    nbOperations = 0;
}

void CompteBancaire::deposer(double montant) {
    if (montant <= 0) {
        return;
    }
    solde += montant;
    nbOperations++;
}

bool CompteBancaire::retirer(double montant) {
    if (montant <= 0 || montant > solde) {
        return false;
    }
    solde -= montant;
    nbOperations++;
    return true;
}

bool CompteBancaire::virerVers(CompteBancaire& autre, double montant) {
    if (!retirer(montant)) {
        return false;
    }
    autre.deposer(montant);
    return true;
}

double CompteBancaire::getSolde() const {
    return solde;
}

std::string CompteBancaire::getTitulaire() const {
    return titulaire;
}

int CompteBancaire::getNbOperations() const {
    return nbOperations;
}

void CompteBancaire::afficher() const {
    std::cout << titulaire << " : " << solde << " EUR (" << nbOperations
              << " operations)" << std::endl;
}
