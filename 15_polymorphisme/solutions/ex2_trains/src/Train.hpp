#ifndef TRAIN_HPP
#define TRAIN_HPP

#include <string>
#include <vector>

class Gare;   // déclaration anticipée : seuls des pointeurs sont utilisés ici

class Train {
public:
    Train(const std::string& id, const std::vector<const Gare*>& trajet);
    virtual ~Train() = default;

    // Méthode modèle : l'algorithme est commun et NON virtuel.
    // Les filles ne peuvent pas le casser ; elles fournissent seulement
    // les réglages via les méthodes virtuelles ci-dessous.
    void avancer(double minutes);

    bool estArrive() const;
    const Gare* getProchainArret() const;
    std::string getId() const;
    std::string getPosition() const;

    // Ce qui distingue les types de trains.
    virtual std::string getType() const = 0;
    virtual double getVitesseMax() const = 0;
    virtual int getPriorite() const = 0;
    virtual double getTempsArret() const;   // virtuelle avec valeur par défaut

private:
    static constexpr double LONGUEUR_SEGMENT_KM = 100.0;

    std::string id;
    std::vector<const Gare*> trajet;
    std::size_t indexGare = 0;
    double kmSurSegment = 0.0;
    double attente = 0.0;
};

#endif
