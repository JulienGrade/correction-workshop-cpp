#pragma once

#include "Vehicule.hpp"

// Fournit std::size_t pour représenter un index.
#include <cstddef>

// Fournit std::unique_ptr pour gérer la propriété des véhicules.
#include <memory>

// Fournit std::vector, un tableau dont la taille peut évoluer.
#include <vector>

class StationLavage {
private:
    // La station possède les véhicules stockés dans ce tableau.
    // Chaque emplacement peut contenir une Voiture ou une Moto
    // grâce à leur classe commune Vehicule.
    std::vector<std::unique_ptr<Vehicule>> vehicules;

public:
    // Reçoit la propriété d'un véhicule et l'ajoute au parc.
    void ajouterVehicule(std::unique_ptr<Vehicule> vehicule);

    // Remplace le véhicule situé à l'index demandé.
    // Renvoie true si le remplacement a réussi, false sinon.
    bool remplacerVehicule(
        std::size_t index,
        std::unique_ptr<Vehicule> vehicule
    );

    // Parcourt le parc et demande à chaque véhicule de se laver.
    void laverTous() const;
};