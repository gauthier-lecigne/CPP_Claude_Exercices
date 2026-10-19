#include <iostream>
#include <vector>

void minMax(const std::vector<int>& v, int& min, int& max) {
    min = v[0];
    max = v[0];
    for (int x : v) {
        if (x < min) min = x;
        if (x > max) max = x;
    }
}

bool diviser(int a, int b, int& quotient, int& reste) {
    if (b == 0) {
        return false;
    }
    quotient = a / b;
    reste = a % b;
    return true;
}

void normaliser(std::vector<double>& v) {
    if (v.empty()) {
        return;
    }
    double max = v[0];
    for (double x : v) {
        if (x > max) max = x;
    }
    if (max == 0) {
        return;   // on ne divise pas par zéro
    }
    for (double& x : v) {   // & : on modifie les éléments du vector
        x = x / max;
    }
}

int main() {
    std::vector<int> v = {4, -2, 17, 8};
    int mini = 0, maxi = 0;
    minMax(v, mini, maxi);
    std::cout << "min = " << mini << ", max = " << maxi << std::endl;

    int q = 0, r = 0;
    if (diviser(17, 5, q, r)) {
        std::cout << "17 / 5 : quotient = " << q << ", reste = " << r << std::endl;
    }
    if (!diviser(17, 0, q, r)) {
        std::cout << "17 / 0 : Division impossible" << std::endl;
    }

    std::vector<double> d = {2, 5, 10};
    normaliser(d);
    for (double x : d) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    return 0;
}
