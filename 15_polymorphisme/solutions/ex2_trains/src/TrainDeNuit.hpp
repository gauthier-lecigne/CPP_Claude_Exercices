#ifndef TRAIN_DE_NUIT_HPP
#define TRAIN_DE_NUIT_HPP

#include "Train.hpp"

// Étape 2 : nouveau type ajouté SANS toucher à Train ni à simuler().
class TrainDeNuit : public Train {
public:
    using Train::Train;
    std::string getType() const override;
    double getVitesseMax() const override;
    int getPriorite() const override;
    double getTempsArret() const override;
};

#endif
