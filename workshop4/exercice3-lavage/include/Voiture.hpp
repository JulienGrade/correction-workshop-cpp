#pragma once

#include "Vehicule.hpp"

class Voiture : public Vehicule{
    public:
        void laver() const override;
};