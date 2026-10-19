/*
 * Exercice 4 — Grille 2D (vector de vector)
 *
 * Un tableau à deux dimensions se représente par un vector de vectors :
 *
 *     std::vector<std::vector<int>> grille(3, std::vector<int>(4, 0));
 *     // 3 lignes, 4 colonnes, toutes à 0
 *     grille[1][2] = 7;   // ligne 1, colonne 2
 *
 * 1. Écris  void afficherGrille(const std::vector<std::vector<int>>& g);
 *    qui affiche la grille, une ligne par ligne de la grille.
 *
 * 2. Écris  std::vector<std::vector<int>> tableMultiplication(int n);
 *    qui renvoie une grille n x n où case[i][j] = (i + 1) * (j + 1).
 *
 * 3. Écris  int sommeGrille(const std::vector<std::vector<int>>& g);
 *
 * 4. Écris  std::vector<std::vector<int>> transposee(const std::vector<std::vector<int>>& g);
 *    La transposée échange lignes et colonnes : t[j][i] = g[i][j].
 *    Une grille 2 x 3 donne une grille 3 x 2.
 *
 * Exemple avec g = {{1, 2, 3}, {4, 5, 6}} :
 *     1 2 3
 *     4 5 6
 *     somme = 21
 *     transposee :
 *     1 4
 *     2 5
 *     3 6
 */

#include <iostream>
#include <vector>

// TODO

int main() {
    // TODO : teste tes fonctions
    return 0;
}
