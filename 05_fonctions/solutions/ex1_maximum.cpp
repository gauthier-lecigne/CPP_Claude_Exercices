#include <iostream>

int maximum(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

// Surcharge : même nom, nombre de paramètres différent.
// On réutilise la version à deux paramètres au lieu de tout réécrire.
int maximum(int a, int b, int c) {
    return maximum(maximum(a, b), c);
}

int valeurAbsolue(int x) {
    return (x < 0) ? -x : x;
}

int main() {
    std::cout << "maximum(3, 8) = " << maximum(3, 8) << std::endl;
    std::cout << "maximum(-1, -5) = " << maximum(-1, -5) << std::endl;
    std::cout << "maximum(4, 9, 2) = " << maximum(4, 9, 2) << std::endl;
    std::cout << "valeurAbsolue(-7) = " << valeurAbsolue(-7) << std::endl;
    std::cout << "valeurAbsolue(3) = " << valeurAbsolue(3) << std::endl;
    return 0;
}
