/*
 * Exercice 3 — Un dé et un jeu
 *
 * 1. Écris une classe De (dé) :
 *      - De(int nbFaces = 6)              nbFaces >= 2, sinon 6
 *      - int lancer()                      tire une valeur entre 1 et nbFaces,
 *                                          la mémorise et la renvoie
 *      - int getDerniereValeur() const     0 si jamais lancé
 *      - int getNbFaces() const
 *
 *    Pour le hasard, mets un générateur en attribut privé :
 *        std::mt19937 generateur;
 *    et initialise-le dans le constructeur :
 *        generateur.seed(std::random_device{}());
 *    puis dans lancer() :
 *        std::uniform_int_distribution<int> dist(1, nbFaces);
 *        derniere = dist(generateur);
 *
 * 2. Écris une classe Joueur :
 *      - Joueur(const std::string& nom)
 *      - void jouerTour(De& de)            lance le dé et ajoute au score
 *      - int getScore() const
 *      - std::string getNom() const
 *
 * 3. Dans le main : deux joueurs jouent à tour de rôle avec un dé à 6 faces.
 *    Le premier à atteindre 30 points gagne. Affiche chaque lancer.
 *
 *    Exemple :
 *        Gauthier lance : 4 (total 4)
 *        Lea lance : 6 (total 6)
 *        ...
 *        Lea gagne avec 31 points !
 *
 * Remarque : De& dans jouerTour. Pourquoi une référence et pas une copie ?
 *            (Pense à ce qui arrive au générateur s'il est copié.)
 */

#include <iostream>
#include <random>
#include <string>

int main() {
    // TODO
    return 0;
}
