#include "Voiture.hpp"
#include "VoitureSport.hpp"

#include <iostream>

void afficher(const Voiture& voiture) {
    std::cout << voiture.getType()
              << " : " << voiture.getVitesse() << " km/h"
              << ", maximum " << voiture.getVitesseMax()
              << ", acceleration " << voiture.getAcceleration()
              << '\n';
}

int main() {
    Voiture voiture{150, 9};
    VoitureSport sportive{250, 12};

    afficher(voiture);
    afficher(sportive);

    voiture.accelerer();
    sportive.accelerer();

    std::cout << "\nApres une acceleration :\n";
    afficher(voiture);
    afficher(sportive);

    std::cout << "\nNombre d'objets crees : "
              << Voiture::getNombreObjetsCrees() << '\n';

    return 0;
}