/*
 * Exercice 1 — Bonjour personnalisé
 *
 * Demande à l'utilisateur son prénom, puis affiche :
 *     Bonjour <prenom>, bienvenue en C++ !
 *
 * Exemple d'exécution :
 *     Ton prenom : Gauthier
 *     Bonjour Gauthier, bienvenue en C++ !
 *
 * Indice : un prénom est du texte, il faut une variable de type std::string
 *          (et #include <string>).
 */

#include <iostream>
#include <string>

int main() {
    std::string username;
    std::cout << "Quel est votre nom : ";
    std::cin >> username;
    
    std::cout << "Votre nom est " << username << "\n";
    return 0;
}
