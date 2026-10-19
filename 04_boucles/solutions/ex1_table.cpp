#include <iomanip>
#include <iostream>

int main() {
    int n = 0;
    std::cout << "Table de : ";
    std::cin >> n;

    for (int i = 1; i <= 10; i++) {
        std::cout << n << " x " << i << " = " << n * i << std::endl;
    }

    // Bonus : grille complète.
    std::cout << "\nToutes les tables :\n";
    for (int ligne = 1; ligne <= 10; ligne++) {
        for (int col = 1; col <= 10; col++) {
            std::cout << std::setw(4) << ligne * col;
        }
        std::cout << "\n";
    }
    return 0;
}
