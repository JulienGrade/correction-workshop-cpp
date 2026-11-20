#pragma once

#include "Instrument.hpp"

// Un Piano est aussi un Instrument.
class Piano : public Instrument {
public:
    // Fournit le comportement spécifique du piano.
    void jouer() const override;
};