#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <ostream>
#include <string>

// Fraction toujours irréductible, avec un dénominateur strictement positif.
class Fraction {
public:
    // Paramètres par défaut : uniquement dans le .hpp.
    // Ce constructeur sert aussi de constructeur par défaut (0/1)
    // et de conversion depuis un entier (Fraction(5) = 5/1).
    Fraction(int numerateur = 0, int denominateur = 1);

    int getNumerateur() const;
    int getDenominateur() const;

    Fraction additionner(const Fraction& autre) const;
    Fraction multiplier(const Fraction& autre) const;
    Fraction inverse() const;
    bool egale(const Fraction& autre) const;
    double versDouble() const;
    std::string toString() const;

    // Bonus
    Fraction operator+(const Fraction& autre) const;
    Fraction operator*(const Fraction& autre) const;
    bool operator==(const Fraction& autre) const;

private:
    static int pgcd(int a, int b);   // utilitaire : ne dépend d'aucun objet
    void simplifier();

    int numerateur;
    int denominateur;
};

// Fonction libre (pas une méthode) : à gauche de << il y a std::cout, pas une Fraction.
std::ostream& operator<<(std::ostream& out, const Fraction& f);

#endif
