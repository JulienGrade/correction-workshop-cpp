#pragma once

class Instrument{
    public:
        virtual ~Instrument() = default;
        virtual void jouer() const=0;
};