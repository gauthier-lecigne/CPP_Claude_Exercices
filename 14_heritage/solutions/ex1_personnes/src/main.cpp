#include <cmath>
#include <iostream>
#include <string>

#include "Etudiant.hpp"
#include "Personne.hpp"
#include "Professeur.hpp"

int reussis = 0;
int total = 0;

void verifier(const std::string& nom, bool condition) {
    total++;
    if (condition) reussis++;
    std::cout << (condition ? "[OK]    " : "[ECHEC] ") << nom << std::endl;
}

// Reçoit n'importe quelle Personne (y compris un Etudiant ou un Professeur).
void presenterTout(const Personne& p) {
    p.sePresenter();
}

int main() {
    Personne anonyme("Alex", -3);
    verifier("age negatif remplace par 0", anonyme.getAge() == 0);

    Etudiant e("Gauthier", 21, "SUPINFO");
    verifier("Etudiant herite de getNom", e.getNom() == "Gauthier");
    verifier("getEcole", e.getEcole() == "SUPINFO");

    e.ajouterNote(12);
    e.ajouterNote(17);
    e.ajouterNote(25);   // ignorée
    verifier("moyenne(12, 17) = 14.5", e.moyenne() == 14.5);

    e.anniversaire();    // méthode héritée
    verifier("anniversaire : 22 ans", e.getAge() == 22);

    Professeur p("Mme Martin", 45, "C++", 3000);
    p.augmenter(10);
    verifier("augmentation de 10 % : 3300", std::abs(p.getSalaire() - 3300) < 0.01);
    p.augmenter(-50);
    verifier("augmentation negative ignoree", std::abs(p.getSalaire() - 3300) < 0.01);
    verifier("getMatiere", p.getMatiere() == "C++");

    std::cout << reussis << "/" << total << " tests reussis\n\n";

    std::cout << "--- Appels directs ---\n";
    e.sePresenter();
    p.sePresenter();

    std::cout << "\n--- Via une reference Personne& ---\n";
    presenterTout(e);
    presenterTout(p);

    /*
     * 1. Via la Personne&, c'est Personne::sePresenter() qui est appelée,
     *    même si l'objet est un Etudiant : sans "virtual", le compilateur
     *    choisit la méthode d'après le TYPE DE LA VARIABLE (Personne&),
     *    au moment de la compilation. Le chapitre 15 corrige ça.
     *
     * 2. nom est private dans Personne : même les classes filles n'y ont
     *    pas accès. Deux corrections :
     *      a) passer nom en protected dans Personne ;
     *      b) utiliser getNom(), qui est public.
     *    On préfère b) : Personne reste seule responsable de ses données.
     *
     * 3. Construction : Personne d'abord, puis Etudiant.
     *    Destruction : Etudiant d'abord, puis Personne (ordre inverse).
     */
    return 0;
}
