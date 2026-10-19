#ifndef VEHICULE_HPP
#define VEHICULE_HPP

#include <string>

class Vehicule {
public:
    Vehicule(const std::string& marque, double vitesseMax);

    std::string getMarque() const;
    double getVitesseMax() const;
    double getKilometrage() const;

    void rouler(double km);
    double tempsTrajet(double km) const;
    std::string decrire() const;

protected:
    // Accessible à Vehicule et à ses filles, pas au reste du programme :
    // c'est un outil interne à la famille, pas un service offert à tous.
    double calculerTemps(double km, double vitesse) const;

private:
    std::string marque;
    double vitesseMax;
    double kilometrage;
};

/*
 * Réponses
 *
 * 1. Non : via un Vehicule*, c'est Vehicule::tempsTrajet qui est appelée
 *    (450 / 90 = 5 h) au lieu de Camion::tempsTrajet (450 / 63 = 7.14 h).
 *    Même problème pour decrire() : on perd "Camion ..." et la charge.
 *    Sans virtual, le choix se fait sur le type du POINTEUR.
 *
 * 2. Déclarer la méthode "virtual" dans Vehicule (et "override" dans les
 *    filles) : le choix se fera alors sur le type réel de l'objet.
 *
 * 3. public : n'importe qui pourrait l'appeler, alors qu'elle n'a pas de
 *    sens hors de la famille Vehicule.
 *    private : Camion ne pourrait pas l'utiliser.
 *    protected : exactement le bon niveau.
 */

#endif
