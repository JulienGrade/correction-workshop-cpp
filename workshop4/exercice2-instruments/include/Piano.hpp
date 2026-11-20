#pragma once

#include "Instrument.hpp"

class Piano : public Instrument{
    public:
        void jouer() const override;
};