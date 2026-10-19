#include <iostream>

int main() {
    int n = 0;
    std::cout << "Un entier : ";
    std::cin >> n;

    // n % 2 == 0 marche aussi pour les négatifs ; tester "== 1" échouerait sur -7.
    if (n % 2 == 0) {
        std::cout << n << " est pair" << std::endl;
    } else {
        std::cout << n << " est impair" << std::endl;
    }

    if (n > 0) {
        std::cout << n << " est positif" << std::endl;
    } else if (n < 0) {
        std::cout << n << " est negatif" << std::endl;
    } else {
        std::cout << n << " est nul" << std::endl;
    }
    return 0;
}
