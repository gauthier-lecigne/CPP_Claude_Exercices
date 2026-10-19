#ifndef TYPES_TRAIN_HPP
#define TYPES_TRAIN_HPP

#include "Train.hpp"

class TGV : public Train {
public:
    using Train::Train;   // hérite du constructeur de Train
    std::string getType() const override;
    double getVitesseMax() const override;
    int getPriorite() const override;
};

class TER : public Train {
public:
    using Train::Train;
    std::string getType() const override;
    double getVitesseMax() const override;
    int getPriorite() const override;
};

class Fret : public Train {
public:
    using Train::Train;
    std::string getType() const override;
    double getVitesseMax() const override;
    int getPriorite() const override;
    double getTempsArret() const override;   // remplace la valeur par défaut
};

#endif
