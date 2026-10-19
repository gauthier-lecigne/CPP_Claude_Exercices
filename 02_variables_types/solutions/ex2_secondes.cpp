#include <iostream>

int main() {
    const int SECONDES_PAR_HEURE = 3600;
    const int SECONDES_PAR_MINUTE = 60;

    int total = 0;
    std::cout << "Nombre de secondes : ";
    std::cin >> total;

    int heures = total / SECONDES_PAR_HEURE;
    int reste = total % SECONDES_PAR_HEURE;      // secondes restantes après les heures
    int minutes = reste / SECONDES_PAR_MINUTE;
    int secondes = reste % SECONDES_PAR_MINUTE;

    std::cout << total << " s = " << heures << " h " << minutes << " min "
              << secondes << " s" << std::endl;
    return 0;
}
