#pragma once

class Voiture {
private:
    int vitesseMax;
    int vitesse;
    int acceleration;

    int limiteVitesse;
    int limiteAcceleration;

    inline static int nombreObjetsCrees{0};

protected:
    Voiture(
        int vitesseMax,
        int acceleration,
        int limiteVitesse,
        int limiteAcceleration
    );

public:
    Voiture();
    Voiture(int vitesseMax, int acceleration);
    Voiture(const Voiture& autre);

    virtual ~Voiture() = default;

    void initialiser(int vitesseMax, int acceleration);
    virtual void accelerer();

    int getVitesseMax() const;
    int getVitesse() const;
    int getAcceleration() const;

    virtual const char* getType() const;

    static int getNombreObjetsCrees();
};