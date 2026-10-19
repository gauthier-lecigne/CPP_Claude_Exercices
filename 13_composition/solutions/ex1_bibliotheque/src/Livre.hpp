#ifndef LIVRE_HPP
#define LIVRE_HPP

#include <string>

class Livre {
public:
    Livre(const std::string& titre, const std::string& auteur, int annee);

    std::string getTitre() const;
    std::string getAuteur() const;
    int getAnnee() const;
    bool estDisponible() const;
    std::string getEmprunteur() const;

    bool emprunter(const std::string& personne);
    bool rendre();
    std::string toString() const;

private:
    std::string titre;
    std::string auteur;
    int annee;
    std::string emprunteur;   // vide = disponible : une seule source de vérité
};

#endif
