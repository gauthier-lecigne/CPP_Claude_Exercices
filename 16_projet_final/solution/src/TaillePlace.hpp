#ifndef TAILLE_PLACE_HPP
#define TAILLE_PLACE_HPP

#include <string>

// Les valeurs numériques permettent de comparer les tailles :
// une place convient si sa taille est >= à la taille demandée.
enum class TaillePlace { Petite = 1, Normale = 2, Grande = 3 };

// "inline" : autorise la définition dans le .hpp, même si plusieurs .cpp l'incluent.
inline bool estAssezGrande(TaillePlace place, TaillePlace demandee) {
    return static_cast<int>(place) >= static_cast<int>(demandee);
}

inline std::string tailleEnTexte(TaillePlace t) {
    switch (t) {
        case TaillePlace::Petite: return "petite";
        case TaillePlace::Normale: return "normale";
        case TaillePlace::Grande: return "grande";
    }
    return "?";
}

#endif
