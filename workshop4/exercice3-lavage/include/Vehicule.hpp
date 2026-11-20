#pragma once

class Vehicule {
    public:
        virtual ~Vehicule() = default;
        virtual void laver() const=0;
};