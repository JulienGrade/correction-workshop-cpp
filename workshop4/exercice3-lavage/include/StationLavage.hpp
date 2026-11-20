#pragma once

#include "Vehicule.hpp"

#include <memory>
#include <vector>

class StationLavage {
private:
    std::vector<std::unique_ptr<Vehicule>> vehicules;

public:
    void ajouterVehicule(std::unique_ptr<Vehicule> vehicule);
    void laverTous() const;
};