#ifndef ETUDIANT_HPP
#define ETUDIANT_HPP

#include <string>
#include <vector>

#include "Personne.hpp"   // include complet obligatoire pour hériter

class Etudiant : public Personne {
public:
    Etudiant(const std::string& nom, int age, const std::string& ecole);

    std::string getEcole() const;
    void ajouterNote(double note);
    double moyenne() const;
    void sePresenter() const;   // redéfinit (masque) celle de Personne

private:
    std::string ecole;
    std::vector<double> notes;
};

#endif
