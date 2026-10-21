/*
 * Exercice 3 — Moyenne de trois notes
 *
 * Demande trois notes ENTIÈRES (int) et affiche leur moyenne
 * avec sa partie décimale.
 *
 * Exemple :
 *     Note 1 : 12
 *     Note 2 : 15
 *     Note 3 : 14
 *     Moyenne : 13.6667
 *
 * Piège : si ton programme affiche 13, relis la partie
 *         "division entière" du cours.
 *
 * Bonus : affiche la moyenne avec exactement 2 décimales (13.67).
 *         Cherche std::fixed et std::setprecision dans <iomanip>.
 */

#include <iostream>
#include <iomanip>

int main() {
    int note1, note2, note3;
    
    std::cout << "Note 1 : ";
    std::cin >> note1;
    
    std::cout << "Note 2 : ";
    std::cin >> note2;
    
    
    std::cout << "Note 3 : ";
    std::cin >> note3;
    
    double moyenne = (note1 + note2 + note3) / 3.0;
    std::cout << std::fixed << std::setprecision(2); // Fixed pour apres la virgule et precision pour le nb de chiffres (ici deux apres virgule)
    std::cout << "Votre moyenne est de : " << moyenne << "\n";

    return 0;
}
