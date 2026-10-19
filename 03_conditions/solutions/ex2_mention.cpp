#include <iostream>

int main() {
    double note = 0.0;
    std::cout << "Note : ";
    std::cin >> note;

    // Comme les else if sont testés dans l'ordre, arrivé à "note < 12"
    // on sait déjà que note >= 10 : inutile de le retester.
    if (note < 0 || note > 20) {
        std::cout << "Note invalide" << std::endl;
    } else if (note < 10) {
        std::cout << "Mention : Ajourne" << std::endl;
    } else if (note < 12) {
        std::cout << "Mention : Admis" << std::endl;
    } else if (note < 14) {
        std::cout << "Mention : Assez bien" << std::endl;
    } else if (note < 16) {
        std::cout << "Mention : Bien" << std::endl;
    } else {
        std::cout << "Mention : Tres bien" << std::endl;
    }
    return 0;
}
