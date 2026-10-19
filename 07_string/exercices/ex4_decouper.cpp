/*
 * Exercice 4 — Découper une chaîne
 *
 * 1. Écris  std::vector<std::string> decouper(const std::string& s, char sep);
 *    qui découpe s à chaque séparateur.
 *        decouper("Lyon;Macon;Dijon", ';')  ->  {"Lyon", "Macon", "Dijon"}
 *
 *    Méthode : parcours la chaîne caractère par caractère en construisant
 *    un "morceau" courant. À chaque séparateur, ajoute le morceau au
 *    résultat et repars d'un morceau vide. N'oublie pas le dernier morceau !
 *
 * 2. Écris  std::string joindre(const std::vector<std::string>& morceaux,
 *                               const std::string& sep);
 *        joindre({"Lyon", "Macon", "Dijon"}, " -> ")  ->  "Lyon -> Macon -> Dijon"
 *
 * 3. Application : demande une ligne au format CSV
 *        Gauthier;Dupont;21;Lille
 *    et affiche :
 *        Prenom : Gauthier
 *        Nom : Dupont
 *        Age : 21 (dans 10 ans : 31)
 *        Ville : Lille
 *    (convertis l'âge avec std::stoi).
 *
 * Ce genre de fonction te servira pour charger un réseau ferroviaire
 * depuis un fichier texte !
 */

#include <iostream>
#include <string>
#include <vector>

int main() {
    // TODO

    return 0;
}
