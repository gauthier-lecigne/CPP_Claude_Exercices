#ifndef PERSONNE_HPP
#define PERSONNE_HPP

#include <string>

class Personne {
public:
    Personne(const std::string& nom, int age);

    std::string getNom() const;
    int getAge() const;
    void anniversaire();
    void sePresenter() const;   // pas virtual : voir la question 1

private:
    std::string nom;
    int age;
};

#endif
