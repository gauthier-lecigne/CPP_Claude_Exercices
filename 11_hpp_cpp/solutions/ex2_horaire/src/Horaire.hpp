#ifndef HORAIRE_HPP
#define HORAIRE_HPP

#include <string>

// Un horaire dans la journée, de 00:00 à 23:59.
class Horaire {
public:
    Horaire(int heures, int minutes);

    int getHeures() const;
    int getMinutes() const;

    void ajouterMinutes(int m);
    int minutesJusqua(const Horaire& autre) const;
    bool estAvant(const Horaire& autre) const;
    std::string toString() const;

private:
    static constexpr int MINUTES_PAR_JOUR = 24 * 60;

    // Méthode privée : un détail d'implémentation, pas une fonctionnalité offerte.
    void normaliser();

    int minutesDepuisMinuit;   // invariant : 0 <= valeur < MINUTES_PAR_JOUR
};

#endif
