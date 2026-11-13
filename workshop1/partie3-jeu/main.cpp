#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

class Heros {
private:
    std::string nom{"Heros"};
    int pv{10};
    int pvMax{10};
    int pa{10};
    bool epeeEquipee{false};
    bool potionDisponible{true};

public:
    Heros() = default;

    Heros(std::string nom, int pv, int pa)
        : nom{nom}, pv{pv}, pvMax{pv}, pa{pa} {
    }

    void affiche() const {
        std::cout << nom << " - " << pv << "/" << pvMax << " PV, "
                  << pa << " PA";
        if (epeeEquipee) {
            std::cout << " - Epee (+3 degats)";
        }
        std::cout << '\n';
    }

    void equiperEpee() {
        epeeEquipee = true;
    }

    void boirePotion() {
        if (!potionDisponible) {
            std::cout << "Tu n'as plus de potion.\n";
            return;
        }

        if (pv == pvMax) {
            std::cout << "Tes PV sont deja au maximum. Tu gardes la potion.\n";
            return;
        }

        const int soin = std::min(5, pvMax - pv);
        pv += soin;
        potionDisponible = false;

        std::cout << nom << " recupere " << soin << " PV.\n";
    }

    int attaque() const {
        const int degats = 1 + std::rand() % pa;
        return degats + (epeeEquipee ? 3 : 0);
    }

    void subitDegat(int degat) {
        pv -= degat;
    }

    bool estVivant() const {
        return pv > 0;
    }
};

class Creature {
private:
    int pv{10};
    int pa{10};
    int niveau{1};

public:
    Creature() = default;

    Creature(int pv, int pa, int niv)
        : pv{pv}, pa{pa}, niveau{niv} {
    }

    void affiche() const {
        std::cout << "Creature niveau " << niveau << " - "
                  << pv << " PV, " << pa << " PA\n";
    }

    int attaque() const {
        return 1 + std::rand() % pa;
    }

    void subitDegat(int degat) {
        pv -= degat;
    }

    bool estVivant() const {
        return pv > 0;
    }
};

int main() {
    std::srand(42);

    Heros heros{"Hrun", 10, 10};
    Creature creature{10, 10, 5};

    heros.affiche();
    creature.affiche();

    while (heros.estVivant() && creature.estVivant()) {
        std::cout << "\n1. Attaquer\n"
                  << "2. Quitter\n"
                  << "3. Equiper l'epee\n"
                  << "4. Boire la potion\n"
                  << "Ton choix : ";

        std::string choix;
        if (!std::getline(std::cin, choix) || choix == "2") {
            std::cout << "Partie terminee.\n";
            return 0;
        }

        if (choix == "3") {
            heros.equiperEpee();
            heros.affiche();
            continue;
        }

        if (choix == "4") {
            heros.boirePotion();
            heros.affiche();
            continue;
        }

        if (choix != "1") {
            std::cout << "Choix invalide. Saisis 1, 2, 3 ou 4.\n";
            continue;
        }

        const int degatsHeros = heros.attaque();
        creature.subitDegat(degatsHeros);
        std::cout << "Hrun inflige " << degatsHeros << " degats.\n";

        if (creature.estVivant()) {
            const int degatsCreature = creature.attaque();
            heros.subitDegat(degatsCreature);
            std::cout << "La creature inflige " << degatsCreature << " degats.\n";
        }

        heros.affiche();
        creature.affiche();
    }

    if (heros.estVivant()) {
        std::cout << "Victoire de Hrun !\n";
    } else {
        std::cout << "Hrun est vaincu.\n";
    }

    return 0;
}