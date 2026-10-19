#include "TypesVehicule.hpp"

// ----- Moto -----
std::string Moto::getType() const { return "Moto"; }
double Moto::getTarifHoraire() const { return 1.0; }
TaillePlace Moto::getTailleMinimale() const { return TaillePlace::Petite; }

// ----- Voiture -----
std::string Voiture::getType() const { return "Voiture"; }
double Voiture::getTarifHoraire() const { return 2.0; }
TaillePlace Voiture::getTailleMinimale() const { return TaillePlace::Normale; }

// ----- Camionnette -----
std::string Camionnette::getType() const { return "Camionnette"; }
double Camionnette::getTarifHoraire() const { return 3.5; }
TaillePlace Camionnette::getTailleMinimale() const { return TaillePlace::Grande; }
double Camionnette::getPlafond() const { return 40.0; }
