#pragma once

#include "Objet.hpp"

class Rectangle : public Objet {
private:
    double largeur;
    double longueur;

public:
    Rectangle(double l, double lg);

    double getLargeur() const;
    double getLongueur() const;

    double aire() const override;
    double perimetre() const override;
    void afficheInfo() const override;
};