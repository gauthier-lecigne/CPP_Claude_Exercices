#include <iostream>

// a et b sont des COPIES de x et y : on échange les copies,
// puis elles sont détruites à la fin de la fonction. x et y n'ont pas bougé.
void echangerValeur(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// a et b sont d'autres noms pour x et y : l'échange les modifie vraiment.
void echangerReference(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// a et b contiennent les adresses de x et y : *a et *b sont x et y.
void echangerPointeur(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int x = 3;
    int y = 8;
    std::cout << "Avant : x = " << x << ", y = " << y << std::endl;

    echangerValeur(x, y);
    std::cout << "Apres echangerValeur : x = " << x << ", y = " << y << std::endl;

    echangerReference(x, y);
    std::cout << "Apres echangerReference : x = " << x << ", y = " << y << std::endl;

    echangerPointeur(&x, &y);   // on passe les ADRESSES
    std::cout << "Apres echangerPointeur : x = " << x << ", y = " << y << std::endl;
    return 0;
}
