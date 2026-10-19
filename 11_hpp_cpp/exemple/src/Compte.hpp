#ifndef COMPTE_HPP
#define COMPTE_HPP

#include <string>

class Compte {
public:
    Compte(const std::string& titulaire, double soldeInitial);

    void deposer(double montant);
    bool retirer(double montant);
    double getSolde() const;
    std::string getTitulaire() const;

private:
    std::string titulaire;
    double solde;
};

#endif
