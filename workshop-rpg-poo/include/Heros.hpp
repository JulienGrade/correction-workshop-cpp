#pragma once

#include "Combattant.hpp"

#include <iosfwd>
#include <string>

class Heros : public Combattant {
private:
    static constexpr int bonusEpee = 3;
    static constexpr int puissancePotion = 5;
    std::string nom;
    bool epeeEquipee{false};
    bool potionDisponible{true};

public:
    Heros(std::string nom = "Heros", int pv = 10, int pa = 10);
    const std::string& getNom() const;
    void affiche() const;
    void equiperEpee();
    void boirePotion();
    int attaque() const;
    void sauvegarder(std::ostream& fichier) const;
    bool charger(std::istream& fichier);
};
