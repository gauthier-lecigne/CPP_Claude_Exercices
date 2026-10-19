#ifndef LIGNE_HPP
#define LIGNE_HPP

#include <string>
#include <vector>

// Déclaration anticipée : on ne manipule ici que des POINTEURS vers Gare,
// le compilateur n'a pas besoin de connaître le contenu de la classe.
class Gare;

class Ligne {
public:
    explicit Ligne(const std::string& nom);

    std::string getNom() const;
    void ajouterGare(const Gare* gare);
    bool dessert(const std::string& nomGare) const;
    std::size_t getNbGares() const;
    const Gare* getTerminus() const;
    std::string toString() const;

private:
    std::string nom;
    std::vector<const Gare*> gares;   // agrégation : la ligne ne possède pas ses gares
};

#endif
