#pragma once

#include <string>

class Heros;
class Creature;

class Sauvegarde {
private:
    std::string chemin;

public:
    explicit Sauvegarde(std::string chemin);
    const std::string& getChemin() const;
    bool ecrire(const Heros& heros, const Creature& creature, int tours) const;
    bool lire(Heros& heros, Creature& creature, int& tours) const;
};
