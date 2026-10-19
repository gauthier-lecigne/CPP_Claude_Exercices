#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "Forme.hpp"

class Triangle : public Forme {
public:
    Triangle(double a, double b, double c);

    std::string nom() const override;
    double aire() const override;
    double perimetre() const override;

private:
    static bool estValide(double a, double b, double c);

    double a;
    double b;
    double c;
};

#endif
