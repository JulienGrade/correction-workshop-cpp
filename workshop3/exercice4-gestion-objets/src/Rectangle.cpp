#include "Rectangle.hpp"

#include <iostream>

Rectangle::Rectangle(double l, double lg) : largeur{l}, longueur{lg} {
}

double Rectangle::getLargeur() const {
    return largeur;
}

double Rectangle::getLongueur() const {
    return longueur;
}

double Rectangle::aire() const {
    return largeur * longueur;
}

double Rectangle::perimetre() const {
    return 2 * (largeur + longueur);
}

void Rectangle::afficheInfo() const {
    std::cout << "Rectangle de largeur " << largeur
              << " et de longueur " << longueur << '\n';
}