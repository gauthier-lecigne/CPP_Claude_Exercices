#include "Billet.hpp"

#include <iostream>

// Définition des attributs static : une seule fois, dans le .cpp.
int Billet::prochainNumero = 1000;
int Billet::nbBilletsActifs = 0;

Billet::Billet(const std::string& passager, const std::string& trajet, double prix)
    : numero(prochainNumero++),          // const : seule la liste d'initialisation le permet
      passager(passager),
      trajet(trajet),
      prix(prix > 0 ? prix : 0.0) {
    nbBilletsActifs++;
    std::cout << "+ billet " << numero << " cree\n";
}

Billet::~Billet() {
    nbBilletsActifs--;
    std::cout << "- billet " << numero << " detruit\n";
}

int Billet::getNumero() const { return numero; }
std::string Billet::getPassager() const { return passager; }
std::string Billet::getTrajet() const { return trajet; }
double Billet::getPrix() const { return prix; }

void Billet::appliquerReductionJeune() {
    prix *= (1.0 - REDUCTION_JEUNE);
}

void Billet::afficher() const {
    std::cout << "[" << numero << "] " << passager << " - " << trajet << " - " << prix
              << " EUR\n";
}

int Billet::getNbBilletsActifs() {   // "static" n'est pas répété dans le .cpp
    return nbBilletsActifs;
}
