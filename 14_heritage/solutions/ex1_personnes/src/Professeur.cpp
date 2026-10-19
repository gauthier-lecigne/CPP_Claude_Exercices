#include "Professeur.hpp"

#include <iostream>

Professeur::Professeur(const std::string& nom, int age, const std::string& matiere,
                       double salaire)
    : Personne(nom, age), matiere(matiere), salaire(salaire > 0 ? salaire : 0.0) {
}

std::string Professeur::getMatiere() const { return matiere; }
double Professeur::getSalaire() const { return salaire; }

void Professeur::augmenter(double pourcentage) {
    if (pourcentage < 0) {
        return;
    }
    salaire *= 1.0 + pourcentage / 100.0;
}

void Professeur::sePresenter() const {
    Personne::sePresenter();
    std::cout << "J'enseigne le " << matiere << "." << std::endl;
}
