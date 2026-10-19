/*
 * Exercice 2 — Renvoyer plusieurs résultats
 *
 * Une fonction ne peut renvoyer qu'UNE valeur avec return. Les références
 * permettent de "renvoyer" plusieurs résultats via des paramètres de sortie.
 *
 * 1. Écris
 *        void minMax(const std::vector<int>& v, int& min, int& max);
 *    qui remplit min et max.
 *
 * 2. Écris
 *        bool diviser(int a, int b, int& quotient, int& reste);
 *    qui renvoie false (et ne touche à rien) si b vaut 0,
 *    sinon remplit quotient et reste et renvoie true.
 *
 * 3. Écris
 *        void normaliser(std::vector<double>& v);
 *    qui divise chaque élément par le maximum du vector (pour que le plus
 *    grand vaille 1). Utilise un range-for avec référence : for (double& x : v)
 *
 * Exemple :
 *     v = {4, -2, 17, 8}  ->  min = -2, max = 17
 *     diviser(17, 5)      ->  quotient = 3, reste = 2
 *     diviser(17, 0)      ->  Division impossible
 *     normaliser({2, 5, 10}) -> {0.2, 0.5, 1}
 */

#include <iostream>
#include <vector>

int main() {
    // TODO

    return 0;
}
