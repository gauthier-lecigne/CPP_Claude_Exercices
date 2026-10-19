#include <iostream>

int main() {
    int annee = 0;
    std::cout << "Annee : ";
    std::cin >> annee;

    bool bissextile = (annee % 4 == 0 && annee % 100 != 0) || (annee % 400 == 0);

    if (bissextile) {
        std::cout << annee << " est bissextile" << std::endl;
    } else {
        std::cout << annee << " n'est pas bissextile" << std::endl;
    }
    return 0;
}
