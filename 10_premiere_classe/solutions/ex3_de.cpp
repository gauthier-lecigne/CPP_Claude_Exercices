#include <iostream>
#include <random>
#include <string>

class De {
public:
    De(int nbFaces = 6) {
        this->nbFaces = (nbFaces >= 2) ? nbFaces : 6;
        derniere = 0;
        generateur.seed(std::random_device{}());
    }

    int lancer() {
        std::uniform_int_distribution<int> dist(1, nbFaces);
        derniere = dist(generateur);
        return derniere;
    }

    int getDerniereValeur() const { return derniere; }
    int getNbFaces() const { return nbFaces; }

private:
    int nbFaces;
    int derniere;
    std::mt19937 generateur;
};

class Joueur {
public:
    Joueur(const std::string& nom) {
        this->nom = nom;
        score = 0;
    }

    // De& : on utilise LE dé de la partie. Avec une copie, on copierait aussi
    // son générateur : deux copies faites au même moment donneraient la même
    // suite de "hasard", et le dé d'origine ne retiendrait pas le lancer.
    void jouerTour(De& de) {
        int valeur = de.lancer();
        score += valeur;
        std::cout << nom << " lance : " << valeur << " (total " << score << ")\n";
    }

    int getScore() const { return score; }
    std::string getNom() const { return nom; }

private:
    std::string nom;
    int score;
};

int main() {
    const int OBJECTIF = 30;
    De de(6);
    Joueur j1("Gauthier");
    Joueur j2("Lea");

    while (true) {
        j1.jouerTour(de);
        if (j1.getScore() >= OBJECTIF) {
            std::cout << j1.getNom() << " gagne avec " << j1.getScore() << " points !\n";
            break;
        }
        j2.jouerTour(de);
        if (j2.getScore() >= OBJECTIF) {
            std::cout << j2.getNom() << " gagne avec " << j2.getScore() << " points !\n";
            break;
        }
    }
    return 0;
}
