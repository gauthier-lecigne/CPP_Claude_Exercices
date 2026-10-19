#include "TypesTrain.hpp"

// ----- TGV -----
std::string TGV::getType() const { return "TGV"; }
double TGV::getVitesseMax() const { return 300.0; }
int TGV::getPriorite() const { return 3; }

// ----- TER -----
std::string TER::getType() const { return "TER"; }
double TER::getVitesseMax() const { return 160.0; }
int TER::getPriorite() const { return 2; }

// ----- Fret -----
std::string Fret::getType() const { return "Fret"; }
double Fret::getVitesseMax() const { return 100.0; }
int Fret::getPriorite() const { return 1; }
double Fret::getTempsArret() const { return 10.0; }
