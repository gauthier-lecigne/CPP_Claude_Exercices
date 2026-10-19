#include <iostream>
#include <vector>

double moyenne(const std::vector<double>& v) {
    double somme = 0.0;
    for (double x : v) {
        somme += x;
    }
    return somme / v.size();
}

// On initialise avec le PREMIER élément, pas avec 0 :
// si toutes les notes sont > 0, un minimum initialisé à 0 resterait 0.
double minimum(const std::vector<double>& v) {
    double min = v[0];
    for (double x : v) {
        if (x < min) {
            min = x;
        }
    }
    return min;
}

double maximum(const std::vector<double>& v) {
    double max = v[0];
    for (double x : v) {
        if (x > max) {
            max = x;
        }
    }
    return max;
}

int nbAuDessus(const std::vector<double>& v, double seuil) {
    int compteur = 0;
    for (double x : v) {
        if (x >= seuil) {
            compteur++;
        }
    }
    return compteur;
}

int main() {
    int n = 0;
    std::cout << "Combien de notes ? ";
    std::cin >> n;

    std::vector<double> notes;
    for (int i = 1; i <= n; i++) {
        double note = 0.0;
        std::cout << "Note " << i << " : ";
        std::cin >> note;
        notes.push_back(note);
    }

    // Les fonctions ci-dessus supposent un vector non vide (v[0], division par size()).
    // On vérifie donc AVANT de les appeler.
    if (notes.empty()) {
        std::cout << "Aucune note." << std::endl;
        return 0;
    }

    std::cout << "Moyenne : " << moyenne(notes) << std::endl;
    std::cout << "Min : " << minimum(notes) << std::endl;
    std::cout << "Max : " << maximum(notes) << std::endl;
    std::cout << "Notes >= 10 : " << nbAuDessus(notes, 10) << std::endl;
    return 0;
}
