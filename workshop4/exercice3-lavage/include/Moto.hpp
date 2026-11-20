#pragma once

#include "Vehicule.hpp"

class Moto : public Vehicule{
    public:
        void laver() const override;
};