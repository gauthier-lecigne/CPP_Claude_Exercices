#include "Train.hpp"

#include <algorithm>
#include <sstream>

#include "Gare.hpp"

Train::Train(const std::string& id, const std::vector<const Gare*>& trajet)
    : id(id), trajet(trajet) {
}

double Train::getTempsArret() const {
    return 2.0;
}

bool Train::estArrive() const {
    return trajet.empty() || indexGare + 1 >= trajet.size();
}

const Gare* Train::getProchainArret() const {
    if (estArrive()) {
        return nullptr;
    }
    return trajet[indexGare + 1];
}

std::string Train::getId() const {
    return id;
}

void Train::avancer(double minutes) {
    double restant = minutes;

    while (restant > 0 && !estArrive()) {
        if (attente > 0) {
            double pause = std::min(attente, restant);
            attente -= pause;
            restant -= pause;
            continue;
        }

        double kmParMinute = getVitesseMax() / 60.0;   // appel virtuel
        double tempsPourFinir = (LONGUEUR_SEGMENT_KM - kmSurSegment) / kmParMinute;

        if (tempsPourFinir > restant) {
            kmSurSegment += kmParMinute * restant;
            restant = 0;
        } else {
            restant -= tempsPourFinir;
            indexGare++;
            kmSurSegment = 0.0;
            if (!estArrive()) {
                attente = getTempsArret();   // appel virtuel : 2 min, 10 min pour le fret...
            }
        }
    }
}

std::string Train::getPosition() const {
    if (trajet.empty()) {
        return "sans trajet";
    }
    const Gare* derniere = trajet[indexGare];
    if (estArrive()) {
        return "arrive a " + derniere->getNom();
    }
    if (attente > 0 || kmSurSegment == 0.0) {
        return "en gare de " + derniere->getNom();
    }
    std::ostringstream s;
    s << "entre " << derniere->getNom() << " et " << getProchainArret()->getNom() << " ("
      << kmSurSegment << " km)";
    return s.str();
}
