#include "Sauvegarde.hpp"

#include "Creature.hpp"
#include "Heros.hpp"

#include <fstream>
#include <utility>

Sauvegarde::Sauvegarde(std::string chemin) : chemin{std::move(chemin)} {
}

const std::string& Sauvegarde::getChemin() const { return chemin; }

bool Sauvegarde::ecrire(const Heros& heros, const Creature& creature, int tours) const {
    std::ofstream fichier{chemin};
    heros.sauvegarder(fichier);
    creature.sauvegarder(fichier);
    fichier << tours << '\n';
    fichier.close();
    return static_cast<bool>(fichier);
}

bool Sauvegarde::lire(Heros& heros, Creature& creature, int& tours) const {
    std::ifstream fichier{chemin};
    Heros herosCharge = heros;
    Creature creatureChargee = creature;
    int toursCharges{};

    // Dans une partie sauvegardable, la créature a survécu à chaque tour.
    if (!herosCharge.charger(fichier) || !creatureChargee.charger(fichier)
        || !(fichier >> toursCharges) || toursCharges < 0 || toursCharges > 9) {
        return false;
    }

    heros = std::move(herosCharge);
    creature = creatureChargee;
    tours = toursCharges;
    return true;
}
