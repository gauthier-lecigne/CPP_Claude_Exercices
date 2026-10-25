/*
 * Exercice 1 — Statistiques sur des notes
 *
 * 1. Demande combien de notes l'utilisateur veut saisir, puis lis-les
 *    dans un std::vector<double> avec push_back.
 * 2. Écris ces fonctions (sans <algorithm>) :
 *       double moyenne(const std::vector<double>& v);
 *       double minimum(const std::vector<double>& v);
 *       double maximum(const std::vector<double>& v);
 *       int    nbAuDessus(const std::vector<double>& v, double seuil);
 * 3. Affiche les résultats.
 *
 * Exemple :
 *     Combien de notes ? 4
 *     Note 1 : 12
 *     Note 2 : 8.5
 *     Note 3 : 15
 *     Note 4 : 10
 *     Moyenne : 11.375
 *     Min : 8.5
 *     Max : 15
 *     Notes >= 10 : 3
 *
 * Réfléchis : avec quelle valeur initialiser minimum ? (Pas 0 !)
 * Que faire si le vector est vide ?
 */

#include <iostream>
#include <vector>


double moyenne(const std::vector<double>& tableau) {
    double somme = 0.0;
    if (tableau.size() == 0) {
        std::cout << "Tableau vide";
        return 0.0;
    }
    for (std::size_t i = 0; i < tableau.size(); i++) {
    somme += tableau[i];
    }
    return somme / tableau.size();
}


double minimum(const std::vector<double>& tableau) {
    if (tableau.size() == 0) {
        std::cout << "Tableau vide";
        return 0.0;
    }
    double maximum_chiffre = tableau[0];
    for (std::size_t i = 1; i < tableau.size(); i++) {
        if (tableau[i] < maximum_chiffre) {
            maximum_chiffre = tableau[i];
        }
    }
    return maximum_chiffre;
}


double maximum(const std::vector<double>& tableau) {
    if (tableau.size() == 0) {
        std::cout << "Tableau vide";
        return 0.0;
    }
    double maximum_chiffre= tableau[0];
    for (std::size_t i = 1; i < tableau.size(); i++) {
        if (tableau[i] > maximum_chiffre) {
            maximum_chiffre = tableau[i];
        }
    }
    return maximum_chiffre;
}


int nbAuDessus(const std::vector<double>& tableau, double limite) {
    int compteur = 0;
    for (std::size_t i = 0; i < tableau.size(); i++) {
        if (tableau[i] >= limite) {
            compteur += 1;
        }
    }
    return compteur;
}

int main() {
    int nb_valeurs;
    std::cout << "Combien de valeur voulez-vous : ";
    std::cin >> nb_valeurs;
    std::vector<double> tableau;
    for (int i = 1; i <= nb_valeurs; i++) {
        double valeur;
        std::cout << "Valeur " << i << " sur " << nb_valeurs << " : ";
        std::cin >> valeur;
        tableau.push_back(valeur);
    }
    
    std::cout << "\n";
    
    
    std::cout << "Moyenne : " << moyenne(tableau) << "\n";
    std::cout << "Minimum : " << minimum(tableau) << "\n";
    std::cout << "Maximum : " << maximum(tableau) << "\n";
    std::cout << "Note au superieur ou egales a : " << 9.5 << " : " << nbAuDessus(tableau, 9.5) << "\n";
    return 0;
}
