#ifndef FORME_HPP
#define FORME_HPP

#include <string>

// Classe abstraite : on ne peut pas créer une "Forme", seulement ses filles.
class Forme {
public:
    virtual ~Forme() = default;   // indispensable : on détruit des filles via des Forme*

    virtual std::string nom() const = 0;
    virtual double aire() const = 0;
    virtual double perimetre() const = 0;

    // Non virtuelle : l'algorithme est le même pour toutes les formes,
    // seuls les nombres changent, et ils viennent des méthodes virtuelles.
    std::string decrire() const;
};

/*
 * Réponses
 *
 * 1. decrire() fait la même chose pour toutes les formes. Ce qui change
 *    (nom, aire, périmètre), elle le demande aux méthodes virtuelles :
 *    le polymorphisme agit à l'intérieur. C'est le patron "méthode modèle".
 *
 * 2. "Forme f;" : erreur, on ne peut pas instancier une classe abstraite.
 *    "std::vector<Forme>" : erreur aussi, pour la même raison. Et même si
 *    Forme n'était pas abstraite, push_back(Cercle(1)) copierait seulement
 *    la partie Forme du cercle (slicing) : d'où vector<unique_ptr<Forme>>.
 *
 * 3. Sans override, "double aire()" (sans const) compile mais crée une
 *    NOUVELLE méthode ; Cercle n'implémente plus "aire() const" et reste
 *    abstrait : erreur à make_unique<Cercle>, loin de la vraie cause.
 *    Avec override, l'erreur est immédiate et claire :
 *    "marked 'override', but does not override".
 */

#endif
