#include "Place.hpp"

#include "Vehicule.hpp"   // nécessaire ici : on appelle getTailleMinimale()

Place::Place(int numero, TaillePlace taille) : numero(numero), taille(taille) {
}

int Place::getNumero() const { return numero; }
TaillePlace Place::getTaille() const { return taille; }
bool Place::estLibre() const { return occupant == nullptr; }

bool Place::peutAccueillir(const Vehicule& v) const {
    // Appel virtuel : Place ne sait pas quel type de véhicule elle reçoit,
    // et n'a pas besoin de le savoir (règle 5).
    return estLibre() && estAssezGrande(taille, v.getTailleMinimale());
}

bool Place::occuper(const Vehicule& v, int heure) {
    if (!peutAccueillir(v)) {
        return false;
    }
    occupant = &v;
    heureEntree = heure;
    return true;
}

void Place::liberer() {
    occupant = nullptr;
    heureEntree = 0;
}

const Vehicule* Place::getOccupant() const { return occupant; }
int Place::getHeureEntree() const { return heureEntree; }
