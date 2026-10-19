#include <iostream>

int main() {
    double celsius = 0.0;

    std::cout << "Temperature en Celsius : ";
    std::cin >> celsius;

    // 9.0 / 5.0 et non 9 / 5 : avec des int, 9 / 5 vaut 1 !
    double fahrenheit = celsius * 9.0 / 5.0 + 32.0;
    double kelvin = celsius + 273.15;

    std::cout << celsius << " C = " << fahrenheit << " F" << std::endl;
    std::cout << celsius << " C = " << kelvin << " K" << std::endl;
    return 0;
}
