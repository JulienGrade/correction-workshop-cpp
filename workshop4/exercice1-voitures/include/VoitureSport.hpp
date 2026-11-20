#pragma once

// La déclaration de Voiture est nécessaire pour en hériter.
#include "Voiture.hpp"

// L'héritage public permet d'utiliser une VoitureSport
// partout où une Voiture est attendue par référence ou pointeur.
class VoitureSport : public Voiture {
public:
    // Crée une sportive avec les valeurs par défaut.
    VoitureSport();

    // Crée une sportive avec les caractéristiques demandées.
    VoitureSport(int vitesseMax, int acceleration);

    // override demande au compilateur de vérifier que cette méthode
    // redéfinit bien une méthode virtuelle de Voiture.
    void accelerer() override;

    // Fournit le nom spécifique de la sportive.
    const char* getType() const override;
};