#include "Etudiant.hpp"

#include <iostream>

Etudiant::Etudiant(const std::string& nom, int age, const std::string& ecole)
    : Personne(nom, age),   // la partie Personne est construite en premier
      ecole(ecole) {
}

std::string Etudiant::getEcole() const {
    return ecole;
}

void Etudiant::ajouterNote(double note) {
    if (note >= 0 && note <= 20) {
        notes.push_back(note);
    }
}

double Etudiant::moyenne() const {
    if (notes.empty()) {
        return 0.0;
    }
    double somme = 0.0;
    for (double n : notes) {
        somme += n;
    }
    return somme / notes.size();
}

void Etudiant::sePresenter() const {
    Personne::sePresenter();   // on complète la version de la mère au lieu de la réécrire
    std::cout << "J'etudie a " << ecole << " (moyenne : " << moyenne() << ")." << std::endl;
}
