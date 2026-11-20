#pragma once

#include "Vehicule.hpp"

// Une Moto est également un Vehicule.
class Moto : public Vehicule {
public:
    // Fournit le comportement de lavage des motos.
    void laver() const override;
};