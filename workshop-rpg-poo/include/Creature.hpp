#pragma once

#include "Combattant.hpp"

#include <iosfwd>

class Creature : public Combattant {
private:
    int niveau;

public:
    Creature(int pv = 10, int pa = 10, int niveau = 1);
    void affiche() const;
    int attaque() const;
    void sauvegarder(std::ostream& fichier) const;
    bool charger(std::istream& fichier);
};
