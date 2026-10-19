#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct Etudiant {
    std::string nom;
    std::vector<double> notes;
};

double moyenne(const Etudiant& e) {
    if (e.notes.empty()) {
        return 0.0;
    }
    double somme = 0.0;
    for (double n : e.notes) {
        somme += n;
    }
    return somme / e.notes.size();
}

void afficher(const Etudiant& e) {
    std::cout << e.nom << " : " << moyenne(e) << " (" << e.notes.size() << " notes)\n";
}

const Etudiant* meilleur(const std::vector<Etudiant>& promo) {
    if (promo.empty()) {
        return nullptr;
    }
    const Etudiant* best = &promo[0];
    for (const Etudiant& e : promo) {
        if (moyenne(e) > moyenne(*best)) {
            best = &e;   // adresse de l'élément DANS le vector (pas d'une copie)
        }
    }
    return best;
}

std::vector<Etudiant> admis(const std::vector<Etudiant>& promo) {
    std::vector<Etudiant> resultat;
    for (const Etudiant& e : promo) {
        if (moyenne(e) >= 10) {
            resultat.push_back(e);
        }
    }
    return resultat;
}

bool compare(const Etudiant& a, const Etudiant& b) {
    return moyenne(a) > moyenne(b);
}

int main() {
    std::vector<Etudiant> promo = {
        {"Gauthier", {12, 15.5, 16}},
        {"Lea", {17, 15}},
        {"Hugo", {9, 7, 10}},
        {"Ines", {}},
    };

    std::cout << "=== Promo ===\n";
    for (const Etudiant& e : promo) {
        afficher(e);
    }

    const Etudiant* best = meilleur(promo);
    if (best != nullptr) {
        std::cout << "Meilleur : " << best->nom << "\n";
    }

    std::cout << "=== Admis ===\n";
    for (const Etudiant& e : admis(promo)) {
        afficher(e);
    }

    // Bonus : tri par moyenne décroissante.
    // ⚠️ Après ce tri, le pointeur "best" pointerait vers une autre case :
    // un pointeur vers un élément de vector n'est plus fiable si le vector change.
    std::sort(promo.begin(), promo.end(), compare);
    std::cout << "=== Classement ===\n";
    for (const Etudiant& e : promo) {
        afficher(e);
    }
    return 0;
}
