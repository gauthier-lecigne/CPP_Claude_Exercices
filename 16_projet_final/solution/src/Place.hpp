#ifndef PLACE_HPP
#define PLACE_HPP

#include "TaillePlace.hpp"

class Vehicule;   // seul un pointeur est stocké : déclaration anticipée

class Place {
public:
    Place(int numero, TaillePlace taille);

    int getNumero() const;
    TaillePlace getTaille() const;
    bool estLibre() const;
    bool peutAccueillir(const Vehicule& v) const;

    bool occuper(const Vehicule& v, int heure);
    void liberer();

    const Vehicule* getOccupant() const;
    int getHeureEntree() const;

private:
    int numero;
    TaillePlace taille;
    const Vehicule* occupant = nullptr;   // agrégation : la place ne possède pas le véhicule
    int heureEntree = 0;
};

#endif
