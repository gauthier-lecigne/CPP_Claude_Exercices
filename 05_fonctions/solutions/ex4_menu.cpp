#include <iostream>

void afficherMenu();
int lireChoix();
int pgcd(int a, int b);
double kmVersMiles(double km);
void afficherRectangle(int largeur, int hauteur);

int main() {
    int choix = -1;

    while (choix != 0) {
        afficherMenu();
        choix = lireChoix();

        if (choix == 1) {
            int a = 0, b = 0;
            std::cout << "Deux entiers : ";
            std::cin >> a >> b;
            std::cout << "PGCD = " << pgcd(a, b) << "\n";
        } else if (choix == 2) {
            double km = 0.0;
            std::cout << "Distance en km : ";
            std::cin >> km;
            std::cout << km << " km = " << kmVersMiles(km) << " miles\n";
        } else if (choix == 3) {
            int l = 0, h = 0;
            std::cout << "Largeur et hauteur : ";
            std::cin >> l >> h;
            afficherRectangle(l, h);
        }
    }

    std::cout << "Au revoir !" << std::endl;
    return 0;
}

void afficherMenu() {
    std::cout << "\n=== MENU ===\n"
              << "1. PGCD de deux nombres\n"
              << "2. Convertir des km en miles\n"
              << "3. Afficher un rectangle d'etoiles\n"
              << "0. Quitter\n";
}

int lireChoix() {
    int choix = -1;
    do {
        std::cout << "Choix : ";
        std::cin >> choix;
    } while (choix < 0 || choix > 3);
    return choix;
}

int pgcd(int a, int b) {
    while (b != 0) {
        int reste = a % b;
        a = b;
        b = reste;
    }
    return a;
}

double kmVersMiles(double km) {
    const double MILES_PAR_KM = 0.621371;
    return km * MILES_PAR_KM;
}

void afficherRectangle(int largeur, int hauteur) {
    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}
