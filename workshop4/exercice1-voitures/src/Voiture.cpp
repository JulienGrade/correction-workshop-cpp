#include "Voiture.hpp"

#include <algorithm>

Voiture::Voiture() : Voiture{100, 3} {
}

Voiture::Voiture(int vitesseMax, int acceleration) {
    initialiser(vitesseMax, acceleration);
    ++nombreObjetsCrees;
}

Voiture::Voiture(const Voiture& autre)
    : vitesseMax{autre.vitesseMax},
      vitesse{autre.vitesse},
      acceleration{autre.acceleration} {
    ++nombreObjetsCrees;
}

void Voiture::initialiser(int vitesseMax, int acceleration) {
    this->vitesseMax = std::clamp(vitesseMax, 0, 100);
    this->acceleration = std::clamp(acceleration, 0, 3);
    vitesse = 0;
}

void Voiture::accelerer() {
    vitesse = std::min(vitesse + acceleration, vitesseMax);
}

int Voiture::getVitesseMax() const {
    return vitesseMax;
}

int Voiture::getVitesse() const {
    return vitesse;
}

int Voiture::getAcceleration() const {
    return acceleration;
}

int Voiture::getNombreObjetsCrees() {
    return nombreObjetsCrees;
}