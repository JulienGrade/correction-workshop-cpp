#pragma once

#include "Creature.hpp"
#include "Heros.hpp"
#include "Sauvegarde.hpp"

class Jeu {
private:
    static constexpr unsigned int graine = 42;
    Heros heros{"Hrun", 10, 10};
    Creature creature{10, 10, 5};
    Sauvegarde sauvegarde{"workshop1-partie.txt"};
    int toursJoues{0};

    void afficherEtat() const;
    void jouerTour();
    void sauvegarder() const;
    void charger();

public:
    void lancer();
};
