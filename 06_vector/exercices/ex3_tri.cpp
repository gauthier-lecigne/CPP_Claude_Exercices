/*
 * Exercice 3 — Tri à bulles
 *
 * Écris  void trierBulles(std::vector<int>& v);
 * qui trie le vector EN PLACE (on modifie l'original, d'où le & sans const).
 *
 * Principe du tri à bulles :
 *   On parcourt le tableau et on compare chaque paire de voisins v[j] et v[j+1].
 *   S'ils sont dans le mauvais ordre, on les échange.
 *   Après un passage complet, le plus grand élément est "remonté" à la fin.
 *   On recommence sur le reste, jusqu'à ce qu'un passage ne fasse aucun échange.
 *
 *   [5, 3, 8, 1]
 *    5>3 échange -> [3, 5, 8, 1]
 *    5<8 ok
 *    8>1 échange -> [3, 5, 1, 8]   <- le 8 est à sa place
 *   on recommence sur [3, 5, 1] ...
 *
 * Pour échanger deux valeurs :
 *     int tmp = v[j];
 *     v[j] = v[j + 1];
 *     v[j + 1] = tmp;
 *   (ou std::swap(v[j], v[j + 1]) de <utility>)
 *
 * Bonus : arrête le tri dès qu'un passage ne fait aucun échange
 *         (le tableau est déjà trié).
 *
 * Vérifie ensuite ton résultat en comparant avec std::sort (<algorithm>).
 */

#include <iostream>
#include <vector>

// TODO

int main() {
    std::vector<int> v = {42, 7, 19, 3, 88, 1, 56, 23};

    // trierBulles(v);
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    // Attendu : 1 3 7 19 23 42 56 88
    return 0;
}
