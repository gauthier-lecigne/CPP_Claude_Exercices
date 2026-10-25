/*
 * Exercice 2 — Manipuler un vector
 *
 * Écris ces fonctions SANS utiliser <algorithm> :
 *
 *   void afficher(const std::vector<int>& v);
 *       Affiche sous la forme [3, 1, 4, 1, 5]
 *       (attention à la virgule : pas de virgule après le dernier !)
 *
 *   std::vector<int> inverse(const std::vector<int>& v);
 *       Renvoie un NOUVEAU vector, dans l'ordre inverse.
 *
 *   int compter(const std::vector<int>& v, int valeur);
 *       Nombre d'occurrences de valeur.
 *
 *   int indiceDe(const std::vector<int>& v, int valeur);
 *       Indice de la première occurrence, ou -1 si absente.
 *
 *   std::vector<int> pairs(const std::vector<int>& v);
 *       Renvoie seulement les nombres pairs.
 *
 * Sortie attendue du main fourni :
 *     v       = [3, 1, 4, 1, 5, 9, 2, 6]
 *     inverse = [6, 2, 9, 5, 1, 4, 1, 3]
 *     compter(1) = 2
 *     indiceDe(5) = 4
 *     indiceDe(7) = -1
 *     pairs   = [4, 2, 6]
 *     vide    = []
 */

#include <iostream>
#include <vector>

void afficher(const std::vector<int>& tableau) {
    std::cout << "[";
    for (std::size_t i = 0; i < tableau.size(); i++) {
        if (i > 0) {
            std::cout << ", ";
        }
        std::cout << tableau[i];
    }
    std::cout << "]" << "\n";
}


std::vector<int> inverse(const std::vector<int>& tableau) {
    std::vector<int> tableau_inversee;
    for (int i = tableau.size()-1; i >= 0; i--) {
        tableau_inversee.push_back(tableau[i]);
    }
    return tableau_inversee;
}


int compter(const std::vector<int>& tableau, int valeur) {
    int compteur = 0;
    for (std::size_t i = 0; i < tableau.size(); i++) {
        if (tableau[i] == valeur) {
            compteur += 1;
        }
    }
    return compteur;
}


int indiceDe(const std::vector<int>& tableau, int valeur) {
    for (std::size_t i = 0; i < tableau.size(); i++) {
        if (tableau[i] == valeur) {
            return i;
        }
    }
    return -1;
}


std::vector<int> pairs(const std::vector<int>& tableau) {
    std::vector<int> vectorPairs;
    for (std::size_t i = 0; i < tableau.size(); i++) {
        if (tableau[i] % 2 == 0) {
            vectorPairs.push_back(tableau[i]);
        }
    }
    return vectorPairs;
}

int main() {
    std::vector<int> v = {3, 1, 4, 1, 5, 9, 2, 6};

    std::cout << "v       = "; afficher(v);
    std::cout << "inverse = "; afficher(inverse(v));
    std::cout << "compter(1) = " << compter(v, 1) << std::endl;
    std::cout << "indiceDe(5) = " << indiceDe(v, 5) << std::endl;
    std::cout << "indiceDe(7) = " << indiceDe(v, 7) << std::endl;
    std::cout << "pairs   = "; afficher(pairs(v));
    std::cout << "vide    = "; afficher(std::vector<int>());
    return 0;
}
