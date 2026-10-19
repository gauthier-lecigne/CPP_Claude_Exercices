#include "Bibliotheque.hpp"

#include <iostream>

void Bibliotheque::ajouter(const Livre& livre) {
    livres.push_back(livre);
}

std::size_t Bibliotheque::getNbLivres() const {
    return livres.size();
}

std::size_t Bibliotheque::getNbDisponibles() const {
    std::size_t n = 0;
    for (const Livre& l : livres) {
        if (l.estDisponible()) {
            n++;
        }
    }
    return n;
}

Livre* Bibliotheque::trouver(const std::string& titre) {
    for (Livre& l : livres) {
        if (l.getTitre() == titre) {
            return &l;
        }
    }
    return nullptr;
}

bool Bibliotheque::emprunter(const std::string& titre, const std::string& personne) {
    Livre* l = trouver(titre);
    // La règle "déjà emprunté" est vérifiée par Livre::emprunter : on ne la duplique pas.
    return l != nullptr && l->emprunter(personne);
}

bool Bibliotheque::rendre(const std::string& titre) {
    Livre* l = trouver(titre);
    return l != nullptr && l->rendre();
}

std::vector<Livre> Bibliotheque::livresDe(const std::string& auteur) const {
    std::vector<Livre> resultat;
    for (const Livre& l : livres) {
        if (l.getAuteur() == auteur) {
            resultat.push_back(l);
        }
    }
    return resultat;
}

void Bibliotheque::afficher() const {
    for (std::size_t i = 0; i < livres.size(); i++) {
        std::cout << i + 1 << ". " << livres[i].toString() << "\n";
    }
}
