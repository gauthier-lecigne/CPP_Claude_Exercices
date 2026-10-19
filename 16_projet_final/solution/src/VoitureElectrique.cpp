#include "VoitureElectrique.hpp"

std::string VoitureElectrique::getType() const { return "Voiture electrique"; }
double VoitureElectrique::getTarifHoraire() const { return 1.0; }
double VoitureElectrique::getPlafond() const { return 12.0; }
