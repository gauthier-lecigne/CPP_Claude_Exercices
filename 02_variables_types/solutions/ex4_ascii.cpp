#include <iostream>

int main() {
    char lettre = ' ';

    std::cout << "Une lettre majuscule : ";
    std::cin >> lettre;

    int code = static_cast<int>(lettre);
    char suivante = static_cast<char>(lettre + 1);
    char minuscule = static_cast<char>(lettre + ('a' - 'A'));   // + 32

    std::cout << "Code ASCII : " << code << std::endl;
    std::cout << "Lettre suivante : " << suivante << std::endl;
    std::cout << "En minuscule : " << minuscule << std::endl;
    return 0;
}
