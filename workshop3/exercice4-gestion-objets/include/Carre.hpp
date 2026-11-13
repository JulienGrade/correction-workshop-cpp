#pragma once

#include "Objet.hpp"

class Carre : public Objet {
private:
    double cote;

public:
    explicit Carre(double c);

    double getCote() const;

    double aire() const override;
    double perimetre() const override;
    void afficheInfo() const override;
};