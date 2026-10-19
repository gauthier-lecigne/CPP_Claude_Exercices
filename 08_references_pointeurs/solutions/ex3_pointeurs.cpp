#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    // Étape 1
    int* p = &a;
    std::cout << "a = " << a << ", &a = " << &a
              << ", p = " << p << ", *p = " << *p << std::endl;
    // &a et p affichent la même adresse ; a et *p valent 10.

    // Étape 2
    *p = 15;
    std::cout << "a = " << a << std::endl;   // 15

    // Étape 3
    p = &b;
    std::cout << "*p = " << *p << std::endl; // 20 : un pointeur PEUT changer de cible

    // Étape 4
    int& r = a;
    r = b;   // ce n'est PAS une redirection : c'est "a = b"
    std::cout << "a = " << a << ", b = " << b << std::endl;   // a = 20, b = 20
    // Une référence est liée à a pour toujours ; r = b copie la VALEUR de b dans a.

    // Étape 5
    int* q = nullptr;
    if (q != nullptr) {
        std::cout << *q << std::endl;
    } else {
        std::cout << "q est nul, on ne le dereference pas" << std::endl;
    }
    // Sans le if : comportement indéfini, en pratique un plantage
    // ("segmentation fault").
    return 0;
}
