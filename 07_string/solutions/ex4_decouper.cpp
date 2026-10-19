#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> decouper(const std::string& s, char sep) {
    std::vector<std::string> morceaux;
    std::string courant;

    for (char c : s) {
        if (c == sep) {
            morceaux.push_back(courant);
            courant.clear();
        } else {
            courant += c;
        }
    }
    morceaux.push_back(courant);   // le dernier morceau n'est suivi d'aucun séparateur
    return morceaux;
}

std::string joindre(const std::vector<std::string>& morceaux, const std::string& sep) {
    std::string resultat;
    for (std::size_t i = 0; i < morceaux.size(); i++) {
        if (i > 0) {
            resultat += sep;
        }
        resultat += morceaux[i];
    }
    return resultat;
}

int main() {
    std::vector<std::string> gares = decouper("Lyon;Macon;Dijon", ';');
    std::cout << joindre(gares, " -> ") << "\n\n";

    std::string ligne;
    std::cout << "Ligne CSV (prenom;nom;age;ville) : ";
    std::getline(std::cin, ligne);

    std::vector<std::string> champs = decouper(ligne, ';');
    if (champs.size() != 4) {
        std::cout << "Format invalide : 4 champs attendus, " << champs.size()
                  << " recus." << std::endl;
        return 1;
    }

    int age = std::stoi(champs[2]);
    std::cout << "Prenom : " << champs[0] << "\n"
              << "Nom : " << champs[1] << "\n"
              << "Age : " << age << " (dans 10 ans : " << age + 10 << ")\n"
              << "Ville : " << champs[3] << std::endl;
    return 0;
}
