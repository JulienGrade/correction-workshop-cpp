#include "Carre.hpp"

#include <iostream>

Carre::Carre(double c) : cote{c} {
}

double Carre::getCote() const {
    return cote;
}

double Carre::aire() const {
    return cote * cote;
}

double Carre::perimetre() const {
    return 4 * cote;
}

void Carre::afficheInfo() const {
    std::cout << "Carre de cote " << cote << '\n';
}