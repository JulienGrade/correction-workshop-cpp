#pragma once

class Voiture {
private:
    int vitesseMax;
    int vitesse;
    int acceleration;

    inline static int nombreObjetsCrees{0};

public:
    Voiture();
    Voiture(int vitesseMax, int acceleration);
    Voiture(const Voiture& autre);

    void initialiser(int vitesseMax, int acceleration);
    void accelerer();

    int getVitesseMax() const;
    int getVitesse() const;
    int getAcceleration() const;

    static int getNombreObjetsCrees();
};