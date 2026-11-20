#include "Voiture.hpp"
#include "VoitureSport.hpp"

#include <iostream>
#include <memory>

void afficher(const Voiture& voiture) {
    std::cout << voiture.getType()
              << " : " << voiture.getVitesse() << " km/h"
              << ", maximum " << voiture.getVitesseMax()
              << ", acceleration " << voiture.getAcceleration()
              << '\n';
}

int main() {
    std::unique_ptr<Voiture> voiture = std::make_unique<Voiture>();
    VoitureSport sportive;

    std::cout << "Au depart :\n";
    afficher(*voiture);
    afficher(sportive);

    voiture->accelerer();
    sportive.accelerer();

    std::cout << "\nApres une acceleration :\n";
    afficher(*voiture);
    afficher(sportive);

    voiture = std::make_unique<VoitureSport>();

    std::cout << "\nApres remplacement par une sportive :\n";
    afficher(*voiture);

    voiture->accelerer();
    sportive.accelerer();

    std::cout << "\nApres une nouvelle acceleration :\n";
    afficher(*voiture);
    afficher(sportive);

    std::cout << "\nNombre d'objets crees : "
              << Voiture::getNombreObjetsCrees() << '\n';

    return 0;
}