#ifndef CARRE_HPP
#define CARRE_HPP

#include "Rectangle.hpp"

// Un carré EST un rectangle : il hérite de aire() et perimetre().
class Carre : public Rectangle {
public:
    explicit Carre(double cote);

    std::string nom() const override;   // seule différence
};

#endif
