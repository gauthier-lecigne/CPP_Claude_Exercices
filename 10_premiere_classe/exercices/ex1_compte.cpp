/*
 * Exercice 1 — Compte bancaire
 *
 * Écris une classe CompteBancaire avec :
 *
 *   Attributs (private) :
 *     - titulaire : std::string
 *     - solde : double
 *     - nbOperations : int       (nombre de dépôts + retraits réussis)
 *
 *   Méthodes (public) :
 *     - CompteBancaire(const std::string& titulaire, double soldeInitial)
 *         Si soldeInitial est négatif, le solde démarre à 0.
 *     - void deposer(double montant)        refuse les montants <= 0
 *     - bool retirer(double montant)        refuse si montant <= 0 ou > solde
 *     - bool virerVers(CompteBancaire& autre, double montant)
 *         retire de ce compte et dépose sur l'autre ; false si impossible
 *     - double getSolde() const
 *     - std::string getTitulaire() const
 *     - int getNbOperations() const
 *     - void afficher() const               "Gauthier : 150 EUR (3 operations)"
 *
 * Décommente le main pour tester.
 *
 * Sortie attendue :
 *     Gauthier : 100 EUR (0 operations)
 *     Lea : 0 EUR (0 operations)
 *     Retrait de 500 refuse
 *     Gauthier : 120 EUR (2 operations)
 *     Lea : 30 EUR (1 operations)
 *     Virement refuse
 *
 * Question : virerVers prend "CompteBancaire& autre". Pourquoi pas
 *            "CompteBancaire autre" (sans &) ? Teste et observe.
 */

#include <iostream>
#include <string>

// TODO : classe CompteBancaire

int main() {
    // CompteBancaire a("Gauthier", 100);
    // CompteBancaire b("Lea", -50);
    // a.afficher();
    // b.afficher();
    //
    // if (!a.retirer(500)) {
    //     std::cout << "Retrait de 500 refuse" << std::endl;
    // }
    // a.deposer(50);
    // a.virerVers(b, 30);
    // a.afficher();
    // b.afficher();
    //
    // if (!b.virerVers(a, 1000)) {
    //     std::cout << "Virement refuse" << std::endl;
    // }
    return 0;
}
