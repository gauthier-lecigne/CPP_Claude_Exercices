#include <cmath>
#include <iostream>
#include <string>

class Rectangle {
public:
    Rectangle(double largeur, double hauteur) {
        this->largeur = (largeur > 0) ? largeur : 1.0;
        this->hauteur = (hauteur > 0) ? hauteur : 1.0;
    }

    double aire() const { return largeur * hauteur; }
    double perimetre() const { return 2 * (largeur + hauteur); }
    bool estCarre() const { return largeur == hauteur; }

    void redimensionner(double facteur) {
        if (facteur <= 0) {
            return;
        }
        largeur *= facteur;
        hauteur *= facteur;
    }

    void setLargeur(double l) {
        if (l > 0) largeur = l;
    }
    void setHauteur(double h) {
        if (h > 0) hauteur = h;
    }

    double getLargeur() const { return largeur; }
    double getHauteur() const { return hauteur; }

    // Une méthode peut lire les attributs privés d'un AUTRE objet de la même classe.
    bool contient(const Rectangle& autre) const {
        return autre.largeur <= largeur && autre.hauteur <= hauteur;
    }

    void dessiner() const {
        int l = static_cast<int>(std::round(largeur));
        int h = static_cast<int>(std::round(hauteur));
        if (l > 40) l = 40;
        if (h > 20) h = 20;
        if (l < 1) l = 1;
        if (h < 1) h = 1;
        for (int i = 0; i < h; i++) {
            std::cout << std::string(l, '*') << "\n";
        }
    }

private:
    double largeur;
    double hauteur;
};

// Petite fonction de test : affiche OK ou ECHEC.
void verifier(const std::string& nom, bool condition) {
    std::cout << (condition ? "[OK]    " : "[ECHEC] ") << nom << std::endl;
}

int main() {
    Rectangle r(4, 3);
    verifier("aire 4x3 = 12", r.aire() == 12);
    verifier("perimetre 4x3 = 14", r.perimetre() == 14);
    verifier("4x3 n'est pas un carre", !r.estCarre());

    Rectangle invalide(-2, 0);
    verifier("valeurs invalides remplacees par 1",
             invalide.getLargeur() == 1 && invalide.getHauteur() == 1);
    verifier("1x1 est un carre", invalide.estCarre());

    r.redimensionner(2);
    verifier("redimensionner(2) donne 8x6", r.getLargeur() == 8 && r.getHauteur() == 6);
    r.redimensionner(-1);
    verifier("redimensionner(-1) ignore", r.getLargeur() == 8);

    r.setLargeur(-5);
    verifier("setLargeur(-5) ignore", r.getLargeur() == 8);
    r.setHauteur(8);
    verifier("setHauteur(8) donne un carre", r.estCarre());

    verifier("8x8 contient 1x1", r.contient(invalide));
    verifier("1x1 ne contient pas 8x8", !invalide.contient(r));

    std::cout << "\nRectangle 6x3 :\n";
    Rectangle(6, 3).dessiner();
    return 0;
}
