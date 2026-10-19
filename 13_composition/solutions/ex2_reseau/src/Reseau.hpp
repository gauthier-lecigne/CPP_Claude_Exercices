#ifndef RESEAU_HPP
#define RESEAU_HPP

#include <memory>
#include <string>
#include <vector>

#include "Gare.hpp"
#include "Ligne.hpp"   // include complet : on stocke des Ligne par valeur

class Reseau {
public:
    const Gare* ajouterGare(const std::string& nom, int nbQuais);
    const Gare* trouverGare(const std::string& nom) const;

    bool ajouterLigne(const std::string& nom, const std::vector<std::string>& nomsGares);
    std::vector<std::string> lignesPassantPar(const std::string& nomGare) const;

    void afficher() const;

private:
    // ⚠️ L'ordre de déclaration compte (voir question 3).
    std::vector<std::unique_ptr<Gare>> gares;   // composition
    std::vector<Ligne> lignes;                  // composition
};

/*
 * Réponses
 *
 * 1. Quand un std::vector<Gare> grandit, il peut déplacer toutes ses gares
 *    ailleurs en mémoire : les Gare* stockés dans les lignes pointeraient
 *    alors dans le vide. Avec unique_ptr, chaque Gare est allouée à part
 *    et ne bouge jamais ; seul le petit unique_ptr est déplacé.
 *
 * 2. La ligne n'a pas créé les gares et n'en est pas propriétaire : c'est le
 *    Reseau qui les détruira. Un delete dans Ligne provoquerait une double
 *    libération (plantage), et casserait les autres lignes qui desservent
 *    la même gare.
 *
 * 3. Il faut détruire les lignes AVANT les gares. Or les attributs sont
 *    détruits dans l'ordre INVERSE de leur déclaration : en déclarant
 *    "gares" puis "lignes", les lignes sont détruites en premier. C'est
 *    sans conséquence ici (le destructeur de Ligne ne lit pas ses gares),
 *    mais c'est la bonne habitude.
 */

#endif
