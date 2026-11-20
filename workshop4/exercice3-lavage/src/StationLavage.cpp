#include "StationLavage.hpp"

#include <utility>

void StationLavage::ajouterVehicule(std::unique_ptr<Vehicule> vehicule) {
    if (vehicule) {
        vehicules.push_back(std::move(vehicule));
    }
}

bool StationLavage::remplacerVehicule(
    std::size_t index,
    std::unique_ptr<Vehicule> vehicule
) {
    if (index >= vehicules.size() || !vehicule) {
        return false;
    }

    vehicules[index] = std::move(vehicule);
    return true;
}

void StationLavage::laverTous() const {
    for (const auto& vehicule : vehicules) {
        vehicule->laver();
    }
}