/*
 * Exercice 2 — Somme jusqu'à zéro
 *
 * L'utilisateur tape des nombres entiers les uns après les autres.
 * Dès qu'il tape 0, le programme s'arrête et affiche :
 *   - combien de nombres ont été saisis (sans compter le 0) ;
 *   - leur somme ;
 *   - leur moyenne (avec décimales) ;
 *   - le plus grand.
 *
 * Exemple :
 *     Nombre (0 pour finir) : 4
 *     Nombre (0 pour finir) : 10
 *     Nombre (0 pour finir) : -2
 *     Nombre (0 pour finir) : 0
 *     3 nombres, somme = 12, moyenne = 4, max = 10
 *
 * Cas à gérer : si le premier nombre est 0, affiche "Aucun nombre saisi".
 *
 * Question : quel est le bon type de boucle ici ?
 */

#include <iostream>

int main() {
    int chiffre;
    int nombre_s = 0;
    int somme = 0;
    double moyenne = 0.0;
    int max = 0;
    do {
        std::cout << "Entrez un chiffre : ";
        std::cin >> chiffre;
        if (chiffre != 0) {
            nombre_s += 1;
            somme = somme + chiffre;
            if (nombre_s == 1 || chiffre > max) {
                max = chiffre;
            }
        }
    } while (chiffre != 0);

    if (nombre_s == 0) {
        std::cout << "Aucun nombre saisi";
    } else {
        std::cout << nombre_s << " nombres,  " << " somme = " <<  somme << ", moyenne = " << somme / nombre_s << ", max = " << max;
    }

    return 0;
}
