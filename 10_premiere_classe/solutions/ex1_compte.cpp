#include <iostream>
#include <string>

class CompteBancaire {
public:
    CompteBancaire(const std::string& titulaire, double soldeInitial) {
        this->titulaire = titulaire;
        solde = (soldeInitial > 0) ? soldeInitial : 0.0;
        nbOperations = 0;
    }

    void deposer(double montant) {
        if (montant <= 0) {
            return;
        }
        solde += montant;
        nbOperations++;
    }

    bool retirer(double montant) {
        if (montant <= 0 || montant > solde) {
            return false;
        }
        solde -= montant;
        nbOperations++;
        return true;
    }

    // "autre" est une référence : on modifie le VRAI compte de destination.
    // Sans &, on déposerait sur une copie détruite à la fin de la méthode :
    // l'argent disparaîtrait !
    bool virerVers(CompteBancaire& autre, double montant) {
        if (!retirer(montant)) {      // on réutilise les règles de retirer
            return false;
        }
        autre.deposer(montant);
        return true;
    }

    double getSolde() const { return solde; }
    std::string getTitulaire() const { return titulaire; }
    int getNbOperations() const { return nbOperations; }

    void afficher() const {
        std::cout << titulaire << " : " << solde << " EUR (" << nbOperations
                  << " operations)" << std::endl;
    }

private:
    std::string titulaire;
    double solde;
    int nbOperations;
};

int main() {
    CompteBancaire a("Gauthier", 100);
    CompteBancaire b("Lea", -50);
    a.afficher();
    b.afficher();

    if (!a.retirer(500)) {
        std::cout << "Retrait de 500 refuse" << std::endl;
    }
    a.deposer(50);
    a.virerVers(b, 30);
    a.afficher();
    b.afficher();

    if (!b.virerVers(a, 1000)) {
        std::cout << "Virement refuse" << std::endl;
    }
    return 0;
}
