#ifndef BIBLIOTHEQUE_HPP
#define BIBLIOTHEQUE_HPP

#include <string>
#include <vector>

#include "Livre.hpp"   // include complet : on stocke des Livre PAR VALEUR

class Bibliotheque {
public:
    void ajouter(const Livre& livre);

    std::size_t getNbLivres() const;
    std::size_t getNbDisponibles() const;

    bool emprunter(const std::string& titre, const std::string& personne);
    bool rendre(const std::string& titre);

    std::vector<Livre> livresDe(const std::string& auteur) const;
    void afficher() const;

private:
    // Le pointeur renvoyé n'est valable que jusqu'au prochain ajouter()
    // (le vector peut se réallouer) : on ne le stocke donc jamais, on l'utilise tout de suite.
    Livre* trouver(const std::string& titre);

    std::vector<Livre> livres;   // composition : la bibliothèque possède ses livres
};

#endif
