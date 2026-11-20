#include "VoitureSport.hpp"

#include <iostream>

VoitureSport::VoitureSport() : VoitureSport{200, 8} {
}

VoitureSport::VoitureSport(int vitesseMax, int acceleration)
    : Voiture{vitesseMax, acceleration, 200, 8} {
}

void VoitureSport::accelerer() {
    std::cout << "Je roule en mode sport\n";
    Voiture::accelerer();
}

const char* VoitureSport::getType() const {
    return "Voiture de sport";
}