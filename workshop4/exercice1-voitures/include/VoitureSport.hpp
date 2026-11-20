#pragma once

#include "Voiture.hpp"

class VoitureSport : public Voiture{
    public:
        VoitureSport();
        VoitureSport(int vitesseMax, int acceleration);

        const char* getType() const override;
};