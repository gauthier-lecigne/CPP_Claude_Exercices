#include "Personne.hpp"

#include <iostream>

Personne::Personne(const std::string& nom, int age)
    : nom(nom), age(age >= 0 ? age : 0) {
}

std::string Personne::getNom() const { return nom; }
int Personne::getAge() const { return age; }

void Personne::anniversaire() {
    age++;
}

void Personne::sePresenter() const {
    std::cout << "Je m'appelle " << nom << ", j'ai " << age << " ans." << std::endl;
}
