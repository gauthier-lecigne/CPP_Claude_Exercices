#include <iostream>
#include <random>

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(1, 100);
    int secret = dist(gen);

    const int ESSAIS_MAX = 7;   // bonus
    int essais = 0;
    int proposition = 0;
    bool gagne = false;

    std::cout << "J'ai choisi un nombre entre 1 et 100. Tu as "
              << ESSAIS_MAX << " essais.\n";

    while (!gagne && essais < ESSAIS_MAX) {
        std::cout << "Ta proposition : ";
        std::cin >> proposition;
        essais++;

        if (proposition < secret) {
            std::cout << "Plus grand\n";
        } else if (proposition > secret) {
            std::cout << "Plus petit\n";
        } else {
            gagne = true;
        }
    }

    if (gagne) {
        std::cout << "Gagne en " << essais << " essais !" << std::endl;
    } else {
        std::cout << "Perdu ! Le nombre etait " << secret << "." << std::endl;
    }
    return 0;
}
