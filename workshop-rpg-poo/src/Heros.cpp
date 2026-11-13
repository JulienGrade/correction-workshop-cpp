#include "Heros.hpp"

#include <iostream>
#include <utility>

Heros::Heros(std::string nom, int pv, int pa)
    : Combattant{pv, pa}, nom{std::move(nom)} {
}

const std::string& Heros::getNom() const { return nom; }

void Heros::affiche() const {
    std::cout << nom << " - " << getPv() << '/' << getPvMax()
              << " PV, " << getPa() << " PA";
    if (epeeEquipee) {
        std::cout << " - Epee (+" << bonusEpee << " degats)";
    }
    std::cout << '\n';
}

void Heros::equiperEpee() { epeeEquipee = true; }

void Heros::boirePotion() {
    if (!potionDisponible) {
        std::cout << "Tu n'as plus de potion.\n";
        return;
    }

    const int soin = soigner(puissancePotion);
    if (soin == 0) {
        std::cout << "Tes PV sont deja au maximum. Tu gardes la potion.\n";
        return;
    }

    potionDisponible = false;
    std::cout << nom << " recupere " << soin << " PV.\n";
}

int Heros::attaque() const {
    return tirerDegats() + (epeeEquipee ? bonusEpee : 0);
}

void Heros::sauvegarder(std::ostream& fichier) const {
    fichier << getPv() << ' ' << epeeEquipee << ' ' << potionDisponible << '\n';
}

bool Heros::charger(std::istream& fichier) {
    int pv{};
    bool epee{};
    bool potion{};
    if (!(fichier >> pv >> epee >> potion) || !restaurerPv(pv)) {
        return false;
    }
    epeeEquipee = epee;
    potionDisponible = potion;
    return true;
}
