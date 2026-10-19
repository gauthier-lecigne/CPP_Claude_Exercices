#ifndef BILLET_HPP
#define BILLET_HPP

#include <string>

class Billet {
public:
    static constexpr double REDUCTION_JEUNE = 0.30;

    Billet(const std::string& passager, const std::string& trajet, double prix);
    ~Billet();

    int getNumero() const;
    std::string getPassager() const;
    std::string getTrajet() const;
    double getPrix() const;

    void appliquerReductionJeune();
    void afficher() const;

    static int getNbBilletsActifs();

private:
    static int prochainNumero;
    static int nbBilletsActifs;

    const int numero;
    std::string passager;
    std::string trajet;
    double prix;
};

/*
 * Réponses aux questions
 *
 * 1. getNbBilletsActifs() ne lit qu'un attribut static, commun à toute la
 *    classe : elle n'a besoin d'aucun billet précis, donc pas de "this".
 *    afficher() lit numero, passager... qui sont propres à CHAQUE billet :
 *    il lui faut un objet, elle ne peut pas être static.
 *
 * 2. afficherBillet reçoit un "const Billet&" : on ne peut appeler que des
 *    méthodes const dessus. Sans le const sur afficher(), erreur :
 *    "passing 'const Billet' as 'this' argument discards qualifiers".
 *
 * 3. "Billet b2 = b1;" est une CONSTRUCTION par copie : autorisée (même si
 *    ici elle donnerait deux billets au même numéro et fausserait le compteur,
 *    car le constructeur de copie généré n'incrémente rien).
 *    "b2 = b1;" est une AFFECTATION : elle voudrait modifier b2.numero, qui
 *    est const. Le compilateur supprime donc l'opérateur d'affectation.
 */

#endif
