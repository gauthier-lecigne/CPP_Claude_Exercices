#include "Gare.hpp"

Gare::Gare(const std::string& nom, int nbQuais) {
    this->nom = nom;
    this->nbQuais = (nbQuais > 0) ? nbQuais : 1;
}

// Bug 2 corrigé : "const" manquant.
// Sans lui : "no declaration matches 'std::string Gare::getNom()'".
// Pour le compilateur, getNom() et getNom() const sont deux méthodes différentes.
std::string Gare::getNom() const {
    return nom;
}

// Bug 3 corrigé : "Gare::" manquant.
// Sans lui, c'est une fonction libre : "non-member function cannot have
// cv-qualifier" (à cause du const) et "'nbQuais' was not declared".
int Gare::getNbQuais() const {
    return nbQuais;
}

// Bug 4 (dans CMakeLists.txt) : src/Affichage.cpp n'était pas compilé.
// Tout compile, mais l'édition de liens échoue :
// "undefined reference to 'afficherGare(Gare const&)'".
