#include <iostream>
#include <string>
#include <vector>

enum class Etat { Disponible, Emprunte };

struct Livre {
    std::string titre;
    std::string auteur;
    int annee;
    Etat etat = Etat::Disponible;
};

// ---------- Fonctions utilitaires ----------

void viderLigne() {
    std::cin.ignore(10000, '\n');
}

std::string etatEnTexte(Etat e) {
    return (e == Etat::Disponible) ? "Disponible" : "Emprunte";
}

void afficherLivre(std::size_t numero, const Livre& l) {
    std::cout << numero << ". " << l.titre << " - " << l.auteur << " (" << l.annee
              << ") [" << etatEnTexte(l.etat) << "]\n";
}

// Lit un numéro et le vérifie. Renvoie false si invalide.
bool lireNumero(const std::vector<Livre>& biblio, std::size_t& indice) {
    int numero = 0;
    std::cout << "Numero du livre : ";
    std::cin >> numero;
    viderLigne();
    if (numero < 1 || numero > static_cast<int>(biblio.size())) {
        std::cout << "Numero invalide.\n";
        return false;
    }
    indice = static_cast<std::size_t>(numero - 1);   // l'utilisateur compte à partir de 1
    return true;
}

// ---------- Actions ----------

void ajouterLivre(std::vector<Livre>& biblio) {
    Livre l;
    std::cout << "Titre : ";
    std::getline(std::cin, l.titre);
    std::cout << "Auteur : ";
    std::getline(std::cin, l.auteur);
    std::cout << "Annee : ";
    std::cin >> l.annee;
    viderLigne();
    biblio.push_back(l);
    std::cout << "Livre ajoute.\n";
}

void listerLivres(const std::vector<Livre>& biblio) {
    if (biblio.empty()) {
        std::cout << "La bibliotheque est vide.\n";
        return;
    }
    for (std::size_t i = 0; i < biblio.size(); i++) {
        afficherLivre(i + 1, biblio[i]);
    }
}

void emprunterLivre(std::vector<Livre>& biblio) {
    std::size_t i = 0;
    if (!lireNumero(biblio, i)) return;

    if (biblio[i].etat == Etat::Emprunte) {
        std::cout << "Deja emprunte.\n";
    } else {
        biblio[i].etat = Etat::Emprunte;
        std::cout << "Vous avez emprunte \"" << biblio[i].titre << "\".\n";
    }
}

void rendreLivre(std::vector<Livre>& biblio) {
    std::size_t i = 0;
    if (!lireNumero(biblio, i)) return;

    if (biblio[i].etat == Etat::Disponible) {
        std::cout << "Ce livre n'etait pas emprunte.\n";
    } else {
        biblio[i].etat = Etat::Disponible;
        std::cout << "Merci, livre rendu.\n";
    }
}

void chercherParAuteur(const std::vector<Livre>& biblio) {
    std::string auteur;
    std::cout << "Auteur : ";
    std::getline(std::cin, auteur);

    bool trouve = false;
    for (std::size_t i = 0; i < biblio.size(); i++) {
        if (biblio[i].auteur == auteur) {
            afficherLivre(i + 1, biblio[i]);
            trouve = true;
        }
    }
    if (!trouve) {
        std::cout << "Aucun livre de cet auteur.\n";
    }
}

int lireChoix() {
    std::cout << "\n1. Ajouter  2. Lister  3. Emprunter  4. Rendre  5. Chercher  0. Quitter\n"
              << "Choix : ";
    int choix = -1;
    std::cin >> choix;
    viderLigne();
    return choix;
}

int main() {
    std::vector<Livre> biblio = {
        {"Le Petit Prince", "Saint-Exupery", 1943},
        {"Les Miserables", "Victor Hugo", 1862},
        {"Notre-Dame de Paris", "Victor Hugo", 1831},
    };

    int choix = -1;
    while (choix != 0) {
        choix = lireChoix();
        switch (choix) {
            case 1: ajouterLivre(biblio); break;
            case 2: listerLivres(biblio); break;
            case 3: emprunterLivre(biblio); break;
            case 4: rendreLivre(biblio); break;
            case 5: chercherParAuteur(biblio); break;
            case 0: std::cout << "Au revoir !\n"; break;
            default: std::cout << "Choix invalide.\n";
        }
    }
    return 0;
}
