#include "Gare.hpp"
#include "Affichage.hpp"

int main() {
    Gare lyon("Lyon Part-Dieu", 4);
    Gare macon("Macon", 2);

    afficherGare(lyon);
    afficherGare(macon);
    return 0;
}
