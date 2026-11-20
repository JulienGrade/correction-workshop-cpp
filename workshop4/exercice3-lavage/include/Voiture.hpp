#pragma once

// Rend la classe Vehicule disponible pour l'héritage.
#include "Vehicule.hpp"

// Une Voiture est un Vehicule.
// Elle peut donc être manipulée via un pointeur Vehicule.
class Voiture : public Vehicule {
public:
    // Fournit la version de laver() spécifique aux voitures.
    // override fait vérifier la redéfinition par le compilateur.
    void laver() const override;
};