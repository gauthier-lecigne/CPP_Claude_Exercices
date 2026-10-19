#include "Parking.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>

#include "Vehicule.hpp"

Parking::Parking(const std::string& nom) : nom(nom) {
}

void Parking::ajouterPlaces(TaillePlace taille, int nombre) {
    for (int i = 0; i < nombre; i++) {
        int numero = static_cast<int>(places.size()) + 1;
        places.push_back(Place(numero, taille));
    }
}

// Règle 3 : on essaie les tailles de la plus petite compatible à la plus grande.
// Les places n'ont pas besoin d'être triées.
Place* Parking::trouverPlaceLibre(const Vehicule& v) {
    const TaillePlace tailles[] = {TaillePlace::Petite, TaillePlace::Normale, TaillePlace::Grande};
    for (TaillePlace t : tailles) {
        for (Place& p : places) {
            if (p.getTaille() == t && p.peutAccueillir(v)) {
                return &p;
            }
        }
    }
    return nullptr;
}

Place* Parking::trouverPlaceDe(const std::string& immatriculation) {
    for (Place& p : places) {
        if (!p.estLibre() && p.getOccupant()->getImmatriculation() == immatriculation) {
            return &p;
        }
    }
    return nullptr;
}

int Parking::entrer(const Vehicule& v, int heure) {
    if (trouverPlaceDe(v.getImmatriculation()) != nullptr) {
        return -1;   // règle 4 : déjà garé
    }
    Place* p = trouverPlaceLibre(v);
    if (p == nullptr) {
        return -1;   // complet pour cette taille
    }
    p->occuper(v, heure);
    return p->getNumero();
}

double Parking::sortir(const std::string& immatriculation, int heure) {
    Place* p = trouverPlaceDe(immatriculation);
    if (p == nullptr) {
        return -1.0;
    }
    double prix = p->getOccupant()->calculerPrix(heure - p->getHeureEntree());   // appel polymorphe
    recette += prix;
    p->liberer();
    return prix;
}

int Parking::getNbPlaces() const {
    return static_cast<int>(places.size());
}

int Parking::getNbPlacesLibres() const {
    int n = 0;
    for (const Place& p : places) {
        if (p.estLibre()) n++;
    }
    return n;
}

int Parking::getNbPlacesLibres(TaillePlace taille) const {
    int n = 0;
    for (const Place& p : places) {
        if (p.estLibre() && p.getTaille() == taille) n++;
    }
    return n;
}

double Parking::getTauxOccupation() const {
    if (places.empty()) {
        return 0.0;
    }
    return static_cast<double>(getNbPlaces() - getNbPlacesLibres()) / getNbPlaces();
}

double Parking::getRecette() const {
    return recette;
}

std::string Parking::formaterHeure(int minutes) {
    std::ostringstream s;
    s << std::setfill('0') << std::setw(2) << minutes / 60 << ":" << std::setw(2) << minutes % 60;
    return s.str();
}

std::string Parking::formaterDuree(int minutes) {
    std::ostringstream s;
    s << minutes / 60 << "h" << std::setfill('0') << std::setw(2) << minutes % 60;
    return s.str();
}

void Parking::afficherEtat(int heure) const {
    int occupees = getNbPlaces() - getNbPlacesLibres();
    std::cout << "===== Parking " << nom << " - " << formaterHeure(heure) << " =====\n"
              << "Occupation : " << occupees << "/" << getNbPlaces() << " ("
              << static_cast<int>(getTauxOccupation() * 100 + 0.5) << " %)    Recette : "
              << recette << " EUR\n";

    for (const Place& p : places) {
        std::cout << " #" << p.getNumero() << " [" << std::left << std::setw(7)
                  << tailleEnTexte(p.getTaille()) << "]  ";
        if (p.estLibre()) {
            std::cout << "libre\n";
            continue;
        }
        const Vehicule* v = p.getOccupant();
        int duree = heure - p.getHeureEntree();
        std::cout << std::setw(30) << v->decrire() << " depuis " << formaterHeure(p.getHeureEntree())
                  << " (" << formaterDuree(duree) << ")  a payer : " << v->calculerPrix(duree)
                  << " EUR\n";
    }
}
