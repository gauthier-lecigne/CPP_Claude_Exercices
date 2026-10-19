#include <iomanip>
#include <iostream>
#include <vector>

// Un alias rend les signatures beaucoup plus lisibles.
using Grille = std::vector<std::vector<int>>;

void afficherGrille(const Grille& g) {
    for (const std::vector<int>& ligne : g) {
        for (int x : ligne) {
            std::cout << std::setw(4) << x;
        }
        std::cout << "\n";
    }
}

Grille tableMultiplication(int n) {
    Grille g(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g[i][j] = (i + 1) * (j + 1);
        }
    }
    return g;
}

int sommeGrille(const Grille& g) {
    int somme = 0;
    for (const std::vector<int>& ligne : g) {
        for (int x : ligne) {
            somme += x;
        }
    }
    return somme;
}

Grille transposee(const Grille& g) {
    if (g.empty()) {
        return Grille();
    }
    std::size_t lignes = g.size();
    std::size_t colonnes = g[0].size();

    // La transposée a "colonnes" lignes et "lignes" colonnes.
    Grille t(colonnes, std::vector<int>(lignes, 0));
    for (std::size_t i = 0; i < lignes; i++) {
        for (std::size_t j = 0; j < colonnes; j++) {
            t[j][i] = g[i][j];
        }
    }
    return t;
}

int main() {
    Grille g = {{1, 2, 3}, {4, 5, 6}};
    afficherGrille(g);
    std::cout << "somme = " << sommeGrille(g) << "\n";
    std::cout << "transposee :\n";
    afficherGrille(transposee(g));

    std::cout << "\nTable 5 x 5 :\n";
    afficherGrille(tableMultiplication(5));
    return 0;
}
