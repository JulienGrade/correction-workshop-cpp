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
    std::unique_ptr<Voiture> voiture =
        std::make_unique<Voiture>(10, 3);

    VoitureSport sportive{20, 8};

    std::cout << "Au depart :\n";
    afficher(*voiture);
    afficher(sportive);

    std::cout << "\nAcceleration de la voiture classique :\n";
    voiture->accelerer();

    std::cout << "\nAcceleration de la sportive :\n";
    sportive.accelerer();

    voiture = std::make_unique<VoitureSport>(20, 8);

    std::cout << "\nApres remplacement par une sportive :\n";
    afficher(*voiture);

    std::cout << "\nAcceleration via le pointeur Voiture :\n";
    voiture->accelerer();

    std::cout << "\nNouvel appel sur la sportive deja au maximum :\n";
    sportive.accelerer();
    afficher(sportive);

    std::cout << "\nNombre d'objets crees : "
              << Voiture::getNombreObjetsCrees() << '\n';

    return 0;
}