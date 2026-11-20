#include "StationLavage.hpp"

#include <utility>

void StationLavage::ajouterVehicule(std::unique_ptr<Vehicule> vehicule) {
    if (vehicule) {
        vehicules.push_back(std::move(vehicule));
    }
}

void StationLavage::laverTous() const {
    for (const auto& vehicule : vehicules) {
        vehicule->laver();
    }
}