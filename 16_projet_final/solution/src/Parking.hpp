#ifndef PARKING_HPP
#define PARKING_HPP

#include <string>
#include <vector>

#include "Place.hpp"
#include "TaillePlace.hpp"

class Vehicule;

class Parking {
public:
    explicit Parking(const std::string& nom);

    void ajouterPlaces(TaillePlace taille, int nombre);

    int entrer(const Vehicule& v, int heure);
    double sortir(const std::string& immatriculation, int heure);

    int getNbPlaces() const;
    int getNbPlacesLibres() const;
    int getNbPlacesLibres(TaillePlace taille) const;   // surcharge
    double getTauxOccupation() const;
    double getRecette() const;

    void afficherEtat(int heure) const;

private:
    Place* trouverPlaceLibre(const Vehicule& v);
    Place* trouverPlaceDe(const std::string& immatriculation);

    static std::string formaterHeure(int minutes);    // "02:15"
    static std::string formaterDuree(int minutes);    // "2h15"

    std::string nom;
    std::vector<Place> places;   // composition : les places appartiennent au parking
    double recette = 0.0;
};

#endif
