#pragma once

#include "Vehicule.hpp"

#include <cstddef>
#include <memory>
#include <vector>

class StationLavage {
    private:
        std::vector<std::unique_ptr<Vehicule>> vehicules;

    public:
        void ajouterVehicule(std::unique_ptr<Vehicule> vehicule);

        bool remplacerVehicule(
            std::size_t index,
            std::unique_ptr<Vehicule> vehicule
        );

    void laverTous() const;
};