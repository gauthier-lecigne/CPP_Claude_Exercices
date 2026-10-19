#include <algorithm>
#include <iostream>
#include <vector>

void trierBulles(std::vector<int>& v) {
    if (v.size() < 2) {
        return;
    }
    // Après chaque passage, le plus grand des éléments restants est à sa place
    // finale : on réduit donc la zone à parcourir (fin--).
    for (std::size_t fin = v.size() - 1; fin > 0; fin--) {
        bool echange = false;
        for (std::size_t j = 0; j < fin; j++) {
            if (v[j] > v[j + 1]) {
                int tmp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = tmp;
                echange = true;
            }
        }
        if (!echange) {
            return;   // bonus : déjà trié, inutile de continuer
        }
    }
}

int main() {
    std::vector<int> v = {42, 7, 19, 3, 88, 1, 56, 23};
    std::vector<int> copie = v;

    trierBulles(v);
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    // Vérification avec la bibliothèque standard.
    std::sort(copie.begin(), copie.end());
    std::cout << (v == copie ? "Identique a std::sort" : "Different de std::sort !")
              << std::endl;
    return 0;
}
