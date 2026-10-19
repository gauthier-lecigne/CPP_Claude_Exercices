#ifndef COMPTE_BANCAIRE_HPP
#define COMPTE_BANCAIRE_HPP

#include <string>

class CompteBancaire {
public:
    CompteBancaire(const std::string& titulaire, double soldeInitial);

    void deposer(double montant);
    bool retirer(double montant);
    bool virerVers(CompteBancaire& autre, double montant);

    double getSolde() const;
    std::string getTitulaire() const;
    int getNbOperations() const;
    void afficher() const;

private:
    std::string titulaire;
    double solde;
    int nbOperations;
};

#endif
