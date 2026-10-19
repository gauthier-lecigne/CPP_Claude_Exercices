/*
 * Exercice 2 — Gestion d'une promo
 *
 * 1. Définis  struct Etudiant { std::string nom; std::vector<double> notes; };
 *
 * 2. Écris :
 *      double moyenne(const Etudiant& e);       // 0 si aucune note
 *      void afficher(const Etudiant& e);        // "Nom : moyenne (n notes)"
 *      const Etudiant* meilleur(const std::vector<Etudiant>& promo);
 *          // pointeur vers l'étudiant de meilleure moyenne, nullptr si promo vide
 *      std::vector<Etudiant> admis(const std::vector<Etudiant>& promo);
 *          // ceux qui ont une moyenne >= 10
 *
 * 3. Dans le main, crée une promo de 4 étudiants avec quelques notes,
 *    affiche-les tous, puis le meilleur, puis la liste des admis.
 *
 * Exemple :
 *     === Promo ===
 *     Gauthier : 14.5 (3 notes)
 *     Lea : 16 (2 notes)
 *     Hugo : 8.66667 (3 notes)
 *     Ines : 0 (0 notes)
 *     Meilleur : Lea
 *     === Admis ===
 *     Gauthier : 14.5 (3 notes)
 *     Lea : 16 (2 notes)
 *
 * Bonus : trie la promo par moyenne décroissante avec std::sort et une
 *         fonction de comparaison :
 *             bool compare(const Etudiant& a, const Etudiant& b) {
 *                 return moyenne(a) > moyenne(b);
 *             }
 *             std::sort(promo.begin(), promo.end(), compare);
 */

#include <iostream>
#include <string>
#include <vector>

int main() {
    // TODO

    return 0;
}
