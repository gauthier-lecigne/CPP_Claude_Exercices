#include <iomanip>
#include <iostream>

int main() {
    int n1 = 0, n2 = 0, n3 = 0;

    std::cout << "Note 1 : ";
    std::cin >> n1;
    std::cout << "Note 2 : ";
    std::cin >> n2;
    std::cout << "Note 3 : ";
    std::cin >> n3;

    // On convertit la somme en double AVANT de diviser.
    double moyenne = static_cast<double>(n1 + n2 + n3) / 3;

    std::cout << "Moyenne : " << moyenne << std::endl;

    // Bonus : 2 décimales exactement.
    std::cout << "Moyenne (2 decimales) : " << std::fixed << std::setprecision(2)
              << moyenne << std::endl;
    return 0;
}
