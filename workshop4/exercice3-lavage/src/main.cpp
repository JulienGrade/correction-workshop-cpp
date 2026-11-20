#include "Moto.hpp"
#include "StationLavage.hpp"
#include "Voiture.hpp"

#include <memory>
#include <utility>

int main() {
    StationLavage station;

    auto voiture1 = std::make_unique<Voiture>();
    auto voiture2 = std::make_unique<Voiture>();
    auto moto = std::make_unique<Moto>();

    station.ajouterVehicule(std::move(voiture1));
    station.ajouterVehicule(std::move(voiture2));
    station.ajouterVehicule(std::move(moto));

    station.laverTous();

    return 0;
}