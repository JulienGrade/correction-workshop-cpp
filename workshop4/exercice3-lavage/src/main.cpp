#include "Moto.hpp"
#include "StationLavage.hpp"
#include "Voiture.hpp"

#include <iostream>
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

    std::cout << "Premier lavage :\n";
    station.laverTous();

    if (!station.remplacerVehicule(0, std::make_unique<Moto>())) {
        std::cerr << "Impossible de remplacer le premier vehicule.\n";
        return 1;
    }

    std::cout << "\nApres remplacement de la premiere voiture par une moto :\n";
    station.laverTous();

    return 0;
}