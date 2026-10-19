#include "Horaire.hpp"

#include <iomanip>
#include <sstream>

Horaire::Horaire(int heures, int minutes) {
    minutesDepuisMinuit = heures * 60 + minutes;
    normaliser();
}

void Horaire::normaliser() {
    minutesDepuisMinuit %= MINUTES_PAR_JOUR;
    if (minutesDepuisMinuit < 0) {
        minutesDepuisMinuit += MINUTES_PAR_JOUR;   // -30 % 1440 == -30 en C++
    }
}

int Horaire::getHeures() const {
    return minutesDepuisMinuit / 60;
}

int Horaire::getMinutes() const {
    return minutesDepuisMinuit % 60;
}

void Horaire::ajouterMinutes(int m) {
    minutesDepuisMinuit += m;
    normaliser();
}

int Horaire::minutesJusqua(const Horaire& autre) const {
    int ecart = autre.minutesDepuisMinuit - minutesDepuisMinuit;
    if (ecart < 0) {
        ecart += MINUTES_PAR_JOUR;   // on passe minuit
    }
    return ecart;
}

bool Horaire::estAvant(const Horaire& autre) const {
    return minutesDepuisMinuit < autre.minutesDepuisMinuit;
}

std::string Horaire::toString() const {
    std::ostringstream flux;   // un "cout" qui écrit dans une string
    flux << std::setfill('0') << std::setw(2) << getHeures() << ":"
         << std::setw(2) << getMinutes();
    return flux.str();
}
