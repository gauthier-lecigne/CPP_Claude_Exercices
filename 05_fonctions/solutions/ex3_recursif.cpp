#include <iostream>

// long long : 20! = 2 432 902 008 176 640 000 dépasse largement
// la limite d'un int (environ 2,1 milliards). Avec int, le résultat déborde
// et devient faux (on appelle ça un "overflow").
long long factorielle(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorielle(n - 1);
}

int puissance(int base, int exposant) {
    if (exposant == 0) {
        return 1;
    }
    return base * puissance(base, exposant - 1);
}

int sommeChiffres(int n) {
    if (n < 10) {
        return n;              // un seul chiffre : c'est lui-même
    }
    return n % 10 + sommeChiffres(n / 10);
}

int main() {
    std::cout << "5! = " << factorielle(5) << std::endl;
    std::cout << "20! = " << factorielle(20) << std::endl;
    std::cout << "2^10 = " << puissance(2, 10) << std::endl;
    std::cout << "sommeChiffres(1234) = " << sommeChiffres(1234) << std::endl;
    return 0;
}
