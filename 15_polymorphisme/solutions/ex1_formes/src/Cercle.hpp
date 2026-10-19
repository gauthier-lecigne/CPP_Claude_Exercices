#ifndef CERCLE_HPP
#define CERCLE_HPP

#include "Forme.hpp"

class Cercle : public Forme {
public:
    explicit Cercle(double rayon);

    std::string nom() const override;
    double aire() const override;
    double perimetre() const override;

private:
    static constexpr double PI = 3.14159265358979;
    double rayon;
};

#endif
