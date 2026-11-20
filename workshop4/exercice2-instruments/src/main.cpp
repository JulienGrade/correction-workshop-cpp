#include "Instrument.hpp"
#include "Piano.hpp"
#include "Saxophone.hpp"

#include <iostream>
#include <memory>
#include <string>

int main() {
    std::cout << "De quel instrument veux-tu jouer ?\n"
              << "1. Saxophone\n"
              << "2. Piano\n"
              << "Ton choix : ";

    std::string choix;
    if (!std::getline(std::cin, choix)) {
        return 0;
    }

    std::unique_ptr<Instrument> instrument;

    if (choix == "1") {
        instrument = std::make_unique<Saxophone>();
    } else if (choix == "2") {
        instrument = std::make_unique<Piano>();
    } else {
        std::cout << "Choix invalide.\n";
        return 1;
    }

    instrument->jouer();

    return 0;
}