/*
 * Exercice 3 — Chiffre de César
 *
 * Le chiffre de César décale chaque lettre de k positions dans l'alphabet.
 * Avec k = 3 : A -> D, B -> E, ..., X -> A, Y -> B, Z -> C.
 *
 * Écris  std::string chiffrer(const std::string& texte, int k);
 *   - les majuscules restent majuscules, les minuscules restent minuscules ;
 *   - les autres caractères (espaces, chiffres, ponctuation) ne changent pas ;
 *   - k peut être négatif (pour déchiffrer) ou > 26.
 *
 * Formule pour une minuscule c :
 *     position = c - 'a'                     (0 pour a, 25 pour z)
 *     nouvelle = (position + k) % 26
 *     -> attention : si le résultat est négatif, ajoute 26
 *     resultat = 'a' + nouvelle
 *
 * Exemple :
 *     Texte : Rendez-vous a Lyon !
 *     Decalage : 3
 *     Chiffre : Uhqghc-yrxv d Obrq !
 *     Dechiffre : Rendez-vous a Lyon !
 *
 * Écris aussi  std::string dechiffrer(const std::string& texte, int k);
 * en une seule ligne, en réutilisant chiffrer.
 */

#include <iostream>
#include <string>

int main() {
    // TODO

    return 0;
}
