/*
 * Exercice 4 — Premier pas avec unique_ptr
 *
 * Voici une struct (on la détaillera au chapitre 09) :
 */

#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Gare {
    std::string nom;
    int quais;
};

/*
 * 1. Crée une Gare "Lyon Part-Dieu" avec 4 quais via std::make_unique<Gare>.
 *    Affiche ses champs avec l'opérateur ->.
 *
 * 2. Écris  void afficherGare(const Gare* g);
 *    qui affiche "Gare inconnue" si g est nullptr, sinon "nom (X quais)".
 *    Appelle-la avec  maGare.get()  (get() donne le pointeur brut)
 *    et avec  nullptr.
 *
 * 3. Crée un std::vector<std::unique_ptr<Gare>> contenant 3 gares
 *    (Lyon, Macon, Dijon) et affiche-les avec une boucle.
 *    Indice : il faut parcourir par référence :
 *        for (const auto& g : gares) { ... g->nom ... }
 *    Pourquoi "for (auto g : gares)" ne compile-t-il pas ?
 *    (Indice : unique = un seul propriétaire, on ne peut pas le copier.)
 *
 * 4. Écris  Gare* trouverGare(const std::vector<std::unique_ptr<Gare>>& gares,
 *                             const std::string& nom);
 *    qui renvoie un pointeur vers la gare portant ce nom, ou nullptr.
 *    Teste avec "Macon" et avec "Paris".
 */

int main() {
    // TODO

    return 0;
}
