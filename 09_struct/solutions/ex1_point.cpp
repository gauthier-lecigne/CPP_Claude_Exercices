#include <cmath>
#include <iostream>
#include <vector>

struct Point {
    double x;
    double y;
};

struct Segment {
    Point debut;
    Point fin;
};

void afficher(const Point& p) {
    std::cout << "(" << p.x << ", " << p.y << ")";
}

double distance(const Point& a, const Point& b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    return std::sqrt(dx * dx + dy * dy);
}

Point milieu(const Point& a, const Point& b) {
    return {(a.x + b.x) / 2, (a.y + b.y) / 2};
}

void deplacer(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double longueur(const Segment& s) {
    return distance(s.debut, s.fin);
}

double perimetre(const std::vector<Point>& polygone) {
    double total = 0.0;
    std::size_t n = polygone.size();
    for (std::size_t i = 0; i < n; i++) {
        // (i + 1) % n : après le dernier point, on revient au premier.
        total += distance(polygone[i], polygone[(i + 1) % n]);
    }
    return total;
}

int main() {
    Point a{0, 0};
    Point b{3, 4};

    std::cout << "A = "; afficher(a);
    std::cout << ", B = "; afficher(b);
    std::cout << "\ndistance(A, B) = " << distance(a, b) << "\n";

    std::cout << "milieu = "; afficher(milieu(a, b)); std::cout << "\n";

    Segment s{a, b};   // copie de a et b AVANT le déplacement

    deplacer(a, 1, 1);
    std::cout << "A deplace de (1, 1) : "; afficher(a); std::cout << "\n";

    std::cout << "longueur du segment = " << longueur(s) << "\n";

    std::vector<Point> carre = {{0, 0}, {2, 0}, {2, 2}, {0, 2}};
    std::cout << "perimetre du carre de cote 2 = " << perimetre(carre) << std::endl;
    return 0;
}
