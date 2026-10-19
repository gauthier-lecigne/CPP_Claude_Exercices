#include <iostream>
#include <vector>

void afficher(const std::vector<int>& v) {
    std::cout << "[";
    for (std::size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size()) {      // pas de virgule après le dernier
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

std::vector<int> inverse(const std::vector<int>& v) {
    std::vector<int> resultat;
    // On parcourt à l'envers. Attention : i est un int ici, car avec un
    // std::size_t (non signé), i >= 0 serait toujours vrai -> boucle infinie !
    for (int i = static_cast<int>(v.size()) - 1; i >= 0; i--) {
        resultat.push_back(v[i]);
    }
    return resultat;
}

int compter(const std::vector<int>& v, int valeur) {
    int n = 0;
    for (int x : v) {
        if (x == valeur) {
            n++;
        }
    }
    return n;
}

int indiceDe(const std::vector<int>& v, int valeur) {
    for (std::size_t i = 0; i < v.size(); i++) {
        if (v[i] == valeur) {
            return static_cast<int>(i);   // on sort dès la première occurrence
        }
    }
    return -1;
}

std::vector<int> pairs(const std::vector<int>& v) {
    std::vector<int> resultat;
    for (int x : v) {
        if (x % 2 == 0) {
            resultat.push_back(x);
        }
    }
    return resultat;
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
