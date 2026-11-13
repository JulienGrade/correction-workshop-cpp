#include "Creature.hpp"

#include <iostream>

Creature::Creature(int pv, int pa, int niveau)
    : Combattant{pv, pa}, niveau{niveau} {
}

void Creature::affiche() const {
    std::cout << "Creature niveau " << niveau << " - "
              << getPv() << " PV, " << getPa() << " PA\n";
}

int Creature::attaque() const { return tirerDegats(); }

void Creature::sauvegarder(std::ostream& fichier) const {
    fichier << getPv() << '\n';
}

bool Creature::charger(std::istream& fichier) {
    int pv{};
    return (fichier >> pv) && restaurerPv(pv);
}
