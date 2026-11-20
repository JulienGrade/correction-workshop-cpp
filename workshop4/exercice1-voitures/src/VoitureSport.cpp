#include "VoitureSport.hpp"

#include <iostream>

// Le constructeur par défaut délègue au constructeur à deux paramètres.
VoitureSport::VoitureSport() : VoitureSport{200, 8} {
}

// Construit la partie Voiture de la sportive.
// Les deux derniers arguments fixent les plafonds à 200 et 8.
VoitureSport::VoitureSport(int vitesseMax, int acceleration)
    : Voiture{vitesseMax, acceleration, 200, 8} {
}

void VoitureSport::accelerer() {
    // Comportement spécifique à la sportive.
    std::cout << "Je roule en mode sport\n";

    // Appelle explicitement la version définie dans Voiture.
    // Elle fait progresser la vitesse jusqu'au maximum de cet objet.
    Voiture::accelerer();
}

const char* VoitureSport::getType() const {
    return "Voiture de sport";
}