#include "Voiture.hpp"

#include <iostream>

int main() {
    Voiture voiture;

    std::cout << "Voiture par defaut : "
              << voiture.getVitesse() << " km/h, maximum "
              << voiture.getVitesseMax() << ", acceleration "
              << voiture.getAcceleration() << '\n';

    voiture.initialiser(8, 3);

    for (int tour = 1; tour <= 4; ++tour) {
        voiture.accelerer();
        std::cout << "Acceleration " << tour << " : "
                  << voiture.getVitesse() << " km/h\n";
    }

    Voiture voitureLimitee{150, 9};

    std::cout << "Parametres limites : maximum "
              << voitureLimitee.getVitesseMax()
              << ", acceleration "
              << voitureLimitee.getAcceleration() << '\n';

    std::cout << "Nombre d'objets crees : "
              << Voiture::getNombreObjetsCrees() << '\n';

    return 0;
}
