// Bug 1 corrigé : include guard ajouté.
// Sans lui, main.cpp inclut Gare.hpp directement PUIS via Affichage.hpp :
// "redefinition of 'class Gare'".
#ifndef GARE_HPP
#define GARE_HPP

#include <string>

// Style corrigé : plus de "using namespace std;" dans le header.
// Il s'imposerait à tous les fichiers qui incluent Gare.hpp.
class Gare {
public:
    Gare(const std::string& nom, int nbQuais);

    std::string getNom() const;
    int getNbQuais() const;

private:
    std::string nom;
    int nbQuais;
};

#endif
