/*
 * Exercice 1 — Géométrie avec une struct Point
 *
 * 1. Définis  struct Point { double x; double y; };
 *
 * 2. Écris :
 *      void afficher(const Point& p);                      // affiche (x, y)
 *      double distance(const Point& a, const Point& b);    // sqrt((xb-xa)^2 + (yb-ya)^2)
 *      Point milieu(const Point& a, const Point& b);
 *      void deplacer(Point& p, double dx, double dy);      // modifie p
 *
 *    std::sqrt est dans <cmath>.
 *
 * 3. Définis  struct Segment { Point debut; Point fin; };
 *    et écris  double longueur(const Segment& s);
 *    (réutilise distance !)
 *
 * 4. Écris  double perimetre(const std::vector<Point>& polygone);
 *    qui fait le tour du polygone (dernier point relié au premier).
 *
 * Sortie attendue :
 *     A = (0, 0), B = (3, 4)
 *     distance(A, B) = 5
 *     milieu = (1.5, 2)
 *     A deplace de (1, 1) : (1, 1)
 *     longueur du segment = 5
 *     perimetre du carre de cote 2 = 8
 */

#include <cmath>
#include <iostream>
#include <vector>

int main() {
    // TODO

    return 0;
}
