#include <iostream>

int main() {
    int compteur = 0;
    int somme = 0;
    int max = 0;
    int n = 0;

    // do...while : il faut lire au moins un nombre avant de pouvoir tester.
    do {
        std::cout << "Nombre (0 pour finir) : ";
        std::cin >> n;

        if (n != 0) {
            // Au premier nombre, max n'a pas encore de vraie valeur :
            // on l'initialise avec ce nombre (sinon max = 0 serait faux
            // si l'utilisateur ne tape que des négatifs).
            if (compteur == 0 || n > max) {
                max = n;
            }
            somme += n;
            compteur++;
        }
    } while (n != 0);

    if (compteur == 0) {
        std::cout << "Aucun nombre saisi" << std::endl;
    } else {
        double moyenne = static_cast<double>(somme) / compteur;
        std::cout << compteur << " nombres, somme = " << somme
                  << ", moyenne = " << moyenne << ", max = " << max << std::endl;
    }
    return 0;
}
