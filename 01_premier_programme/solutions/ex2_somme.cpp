#include <iostream>

int main() {
    int a;
    int b;

    std::cout << "Premier nombre : ";
    std::cin >> a;
    std::cout << "Deuxieme nombre : ";
    std::cin >> b;
    // Bonus : std::cin >> a >> b; lit les deux à la suite.

    std::cout << a << " + " << b << " = " << a + b << std::endl;
    std::cout << a << " - " << b << " = " << a - b << std::endl;
    std::cout << a << " * " << b << " = " << a * b << std::endl;
    return 0;
}
