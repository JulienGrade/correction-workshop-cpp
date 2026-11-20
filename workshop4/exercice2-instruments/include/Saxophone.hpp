#pragma once

// Rend la déclaration d'Instrument disponible pour l'héritage.
#include "Instrument.hpp"

// Un Saxophone est un Instrument.
// L'héritage public permet de le manipuler via Instrument.
class Saxophone : public Instrument {
public:
    // Fournit la version de jouer() spécifique au saxophone.
    // override vérifie que la signature correspond bien
    // à une méthode virtuelle de la classe Instrument.
    void jouer() const override;
};