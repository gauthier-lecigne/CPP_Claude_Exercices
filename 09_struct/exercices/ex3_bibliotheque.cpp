/*
 * Exercice 3 — Mini bibliothèque (programme complet à menu)
 *
 * Données :
 *     enum class Etat { Disponible, Emprunte };
 *
 *     struct Livre {
 *         std::string titre;
 *         std::string auteur;
 *         int annee;
 *         Etat etat = Etat::Disponible;
 *     };
 *
 * Le programme garde un std::vector<Livre> et propose en boucle :
 *     1. Ajouter un livre        (titre et auteur avec getline !)
 *     2. Lister les livres       (avec [Disponible] / [Emprunte])
 *     3. Emprunter un livre      (par son numéro dans la liste ; refuse s'il est déjà emprunté)
 *     4. Rendre un livre
 *     5. Chercher par auteur     (affiche tous ses livres)
 *     0. Quitter
 *
 * Contraintes :
 *   - une fonction par action, le main ne fait qu'appeler ;
 *   - les fonctions qui modifient la bibliothèque prennent std::vector<Livre>& ;
 *   - celles qui lisent seulement prennent const std::vector<Livre>& ;
 *   - attention au piège cin >> puis getline (voir chapitre 07) ;
 *   - vérifie que le numéro saisi existe avant d'accéder au vector.
 *
 * Pour démarrer plus vite, ajoute 3 livres dans le vector au lancement.
 *
 * Cet exercice est un bon "boss de fin" de la partie 1 : prends ton temps.
 * Au chapitre 13, tu réécriras la même chose en orienté objet, et tu
 * verras la différence.
 */

#include <iostream>
#include <string>
#include <vector>

int main() {
    // TODO

    return 0;
}
