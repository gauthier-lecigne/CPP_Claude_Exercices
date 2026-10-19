#include "Fraction.hpp"

Fraction::Fraction(int numerateur, int denominateur)
    : numerateur(numerateur), denominateur(denominateur == 0 ? 1 : denominateur) {
    simplifier();
}

int Fraction::pgcd(int a, int b) {
    if (a < 0) a = -a;
    if (b < 0) b = -b;
    while (b != 0) {
        int reste = a % b;
        a = b;
        b = reste;
    }
    return a;
}

void Fraction::simplifier() {
    // Invariant 1 : dénominateur positif, le signe passe au numérateur.
    if (denominateur < 0) {
        numerateur = -numerateur;
        denominateur = -denominateur;
    }
    // Invariant 3 : zéro s'écrit 0/1.
    if (numerateur == 0) {
        denominateur = 1;
        return;
    }
    // Invariant 2 : irréductible.
    int d = pgcd(numerateur, denominateur);
    numerateur /= d;
    denominateur /= d;
}

int Fraction::getNumerateur() const {
    return numerateur;
}

int Fraction::getDenominateur() const {
    return denominateur;
}

// a/b + c/d = (ad + cb) / bd ; le constructeur simplifie le résultat.
Fraction Fraction::additionner(const Fraction& autre) const {
    return Fraction(numerateur * autre.denominateur + autre.numerateur * denominateur,
                    denominateur * autre.denominateur);
}

Fraction Fraction::multiplier(const Fraction& autre) const {
    return Fraction(numerateur * autre.numerateur, denominateur * autre.denominateur);
}

Fraction Fraction::inverse() const {
    return Fraction(denominateur, numerateur);
}

// Comme les deux fractions sont irréductibles, il suffit de comparer les termes.
bool Fraction::egale(const Fraction& autre) const {
    return numerateur == autre.numerateur && denominateur == autre.denominateur;
}

double Fraction::versDouble() const {
    return static_cast<double>(numerateur) / denominateur;
}

std::string Fraction::toString() const {
    if (denominateur == 1) {
        return std::to_string(numerateur);
    }
    return std::to_string(numerateur) + "/" + std::to_string(denominateur);
}

// ----- Bonus : les opérateurs réutilisent les méthodes -----

Fraction Fraction::operator+(const Fraction& autre) const {
    return additionner(autre);
}

Fraction Fraction::operator*(const Fraction& autre) const {
    return multiplier(autre);
}

bool Fraction::operator==(const Fraction& autre) const {
    return egale(autre);
}

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    out << f.toString();
    return out;   // renvoyer le flux permet d'enchaîner : cout << a << b
}
