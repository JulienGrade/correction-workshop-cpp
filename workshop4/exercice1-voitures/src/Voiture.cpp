#include "Voiture.hpp"

#include <algorithm>

Voiture::Voiture() : Voiture{100, 3} {
}

Voiture::Voiture(int vitesseMax, int acceleration)
    : Voiture{vitesseMax, acceleration, 100, 3} {
}

Voiture::Voiture(
    int vitesseMax,
    int acceleration,
    int limiteVitesse,
    int limiteAcceleration
)
    : limiteVitesse{limiteVitesse},
      limiteAcceleration{limiteAcceleration} {
    initialiser(vitesseMax, acceleration);
    ++nombreObjetsCrees;
}

Voiture::Voiture(const Voiture& autre)
    : vitesseMax{autre.vitesseMax},
      vitesse{autre.vitesse},
      acceleration{autre.acceleration},
      limiteVitesse{autre.limiteVitesse},
      limiteAcceleration{autre.limiteAcceleration} {
    ++nombreObjetsCrees;
}

void Voiture::initialiser(int vitesseMax, int acceleration) {
    this->vitesseMax = std::clamp(vitesseMax, 0, limiteVitesse);
    this->acceleration = std::clamp(acceleration, 0, limiteAcceleration);
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

const char* Voiture::getType() const {
    return "Voiture";
}

int Voiture::getNombreObjetsCrees() {
    return nombreObjetsCrees;
}