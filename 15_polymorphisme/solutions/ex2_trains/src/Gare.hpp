#ifndef GARE_HPP
#define GARE_HPP

#include <string>

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
