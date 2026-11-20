#include "VoitureSport.hpp"

VoitureSport::VoitureSport() : VoitureSport{200, 8} {
}

VoitureSport::VoitureSport(int vitesseMax, int acceleration)
    : Voiture{vitesseMax, acceleration, 200, 8} {
}

const char* VoitureSport::getType() const {
    return "Voiture de sport";
}