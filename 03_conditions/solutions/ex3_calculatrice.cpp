#include <iostream>

int main() {
    double a = 0.0, b = 0.0;
    char op = ' ';

    std::cout << "Calcul : ";
    std::cin >> a >> op >> b;

    switch (op) {
        case '+':
            std::cout << "Resultat : " << a + b << std::endl;
            break;
        case '-':
            std::cout << "Resultat : " << a - b << std::endl;
            break;
        case '*':
            std::cout << "Resultat : " << a * b << std::endl;
            break;
        case '/':
            if (b == 0) {
                std::cout << "Erreur : division par zero" << std::endl;
            } else {
                std::cout << "Resultat : " << a / b << std::endl;
            }
            break;
        default:
            std::cout << "Erreur : operateur inconnu" << std::endl;
    }
    return 0;
}
