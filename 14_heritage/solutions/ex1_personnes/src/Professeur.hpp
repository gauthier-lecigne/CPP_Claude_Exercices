#ifndef PROFESSEUR_HPP
#define PROFESSEUR_HPP

#include <string>

#include "Personne.hpp"

class Professeur : public Personne {
public:
    Professeur(const std::string& nom, int age, const std::string& matiere, double salaire);

    std::string getMatiere() const;
    double getSalaire() const;
    void augmenter(double pourcentage);
    void sePresenter() const;

private:
    std::string matiere;
    double salaire;
};

#endif
