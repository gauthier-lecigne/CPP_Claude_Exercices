#include <iostream>

int main() {
    int h = 0;
    do {
        std::cout << "Hauteur (1 a 20) : ";
        std::cin >> h;
    } while (h < 1 || h > 20);

    // a) Triangle rectangle : i étoiles à la ligne i.
    for (int i = 1; i <= h; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // b) Triangle inversé : on part de h et on descend.
    for (int i = h; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    std::cout << "\n";

    // c) Pyramide : (h - i) espaces puis (2i - 1) étoiles.
    for (int i = 1; i <= h; i++) {
        for (int j = 0; j < h - i; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < 2 * i - 1; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}
