#include <iostream>

// Prototypes : le main peut appeler ces fonctions avant leur définition.
bool estPremier(int n);
void afficherPremiers(int limite);

int main() {
    int limite = 0;
    std::cout << "Limite : ";
    std::cin >> limite;

    afficherPremiers(limite);
    return 0;
}

bool estPremier(int n) {
    if (n < 2) {
        return false;
    }
    // Si n = a * b avec a <= b, alors a <= racine(n).
    // Il suffit donc de tester les diviseurs d tels que d * d <= n.
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            return false;   // on a trouvé un diviseur : inutile de continuer
        }
    }
    return true;
}

void afficherPremiers(int limite) {
    for (int i = 2; i <= limite; i++) {
        if (estPremier(i)) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
}
