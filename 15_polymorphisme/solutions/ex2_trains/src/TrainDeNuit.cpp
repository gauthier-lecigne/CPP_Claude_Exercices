#include "TrainDeNuit.hpp"

std::string TrainDeNuit::getType() const { return "Nuit"; }
double TrainDeNuit::getVitesseMax() const { return 140.0; }
int TrainDeNuit::getPriorite() const { return 2; }
double TrainDeNuit::getTempsArret() const { return 20.0; }
