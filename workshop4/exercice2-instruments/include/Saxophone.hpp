#pragma once

#include "Instrument.hpp"

class Saxophone : public Instrument{
    public:
        void jouer() const override;
};