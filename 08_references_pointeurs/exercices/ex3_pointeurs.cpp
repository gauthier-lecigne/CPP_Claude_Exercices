/*
 * Exercice 3 — Manipuler des pointeurs
 *
 * Complète le programme en suivant les étapes. Pour chaque étape,
 * ÉCRIS D'ABORD en commentaire ce que tu penses que le programme va
 * afficher, PUIS compile et vérifie.
 */

#include <iostream>

int main() {
    int a = 10;
    int b = 20;

    // Étape 1 : crée un pointeur p qui pointe vers a.
    //           Affiche a, &a, p et *p.
    //           Prédiction : ...

    // Étape 2 : via p uniquement (sans écrire "a ="), mets a à 15.
    //           Affiche a.

    // Étape 3 : fais pointer p vers b. Affiche *p.

    // Étape 4 : crée une référence r vers a. Fais r = b; puis affiche a et b.
    //           Est-ce que r "pointe" maintenant vers b ? Pourquoi ?

    // Étape 5 : crée int* q = nullptr;
    //           Écris un if qui n'affiche *q QUE si q n'est pas nul.
    //           Que se passerait-il sans le if ? (Ne le teste pas forcément !)

    (void)a; (void)b;   // supprime cette ligne quand tu as commencé
    return 0;
}
