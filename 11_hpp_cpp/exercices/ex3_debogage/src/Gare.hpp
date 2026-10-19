#include <string>

using namespace std;

class Gare {
public:
    Gare(const string& nom, int nbQuais);

    string getNom() const;
    int getNbQuais() const;

private:
    string nom;
    int nbQuais;
};
