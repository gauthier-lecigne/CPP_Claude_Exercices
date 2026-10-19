/*
 * Exercice 2 — Convertir des secondes
 *
 * Demande un nombre de secondes (entier) et affiche l'équivalent
 * en heures, minutes et secondes.
 *
 * Exemple :
 *     Nombre de secondes : 3725
 *     3725 s = 1 h 2 min 5 s
 *
 * Indice : utilise la division entière / et le reste %.
 *          Une heure = 3600 secondes.
 */

#include <iostream>

int main() {
    int secondes;
    std::cout << "Entrez un nombre de secondes : ";
    std::cin >> secondes;
    
    int heures = secondes / 3600;
    int minutes = secondes / 60 - (heures*3600)/60;
    int secondes_restantes = secondes % 60;
    
    
    std::cout << heures << " , " << minutes << " , " << secondes_restantes;

    return 0;
}
