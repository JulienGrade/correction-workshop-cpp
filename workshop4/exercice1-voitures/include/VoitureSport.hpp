#pragma once

#include "Voiture.hpp"

class VoitureSport : public Voiture {
public:
    VoitureSport();
    VoitureSport(int vitesseMax, int acceleration);

    void accelerer() override;
    const char* getType() const override;
};