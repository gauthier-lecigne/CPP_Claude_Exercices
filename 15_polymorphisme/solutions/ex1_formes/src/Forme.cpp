#include "Forme.hpp"

#include <sstream>

std::string Forme::decrire() const {
    std::ostringstream s;
    s << nom() << " : aire = " << aire() << ", perimetre = " << perimetre();
    return s.str();
}
