#include "Combattant.hpp"

#include <algorithm>
#include <cstdlib>

Combattant::Combattant(int pv, int pa) : pv{pv}, pvMax{pv}, pa{pa} {
}

int Combattant::tirerDegats() const {
    return 1 + std::rand() % pa;
}

int Combattant::soigner(int maximum) {
    const int soin = std::min(maximum, pvMax - pv);
    pv += soin;
    return soin;
}

int Combattant::getPv() const { return pv; }
int Combattant::getPvMax() const { return pvMax; }
int Combattant::getPa() const { return pa; }

void Combattant::subitDegat(int degats) { pv -= degats; }
bool Combattant::estVivant() const { return pv > 0; }

bool Combattant::restaurerPv(int valeur) {
    if (valeur <= 0 || valeur > pvMax) {
        return false;
    }
    pv = valeur;
    return true;
}
