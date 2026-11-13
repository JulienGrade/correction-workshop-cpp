#include <algorithm>
#include <cstdlib>
#include <fstream>
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

    void sauvegarder(std::ostream& fichier) const {
        fichier << pv << ' ' << epeeEquipee << ' ' << potionDisponible << '\n';
    }

    bool charger(std::istream& fichier) {
        return (fichier >> pv >> epeeEquipee >> potionDisponible)
            && pv > 0 && pv <= pvMax;
    }
};

class Creature {
private:
    int pv{10};
    int pvMax{10};
    int pa{10};
    int niveau{1};

public:
    Creature() = default;

    Creature(int pv, int pa, int niv)
        : pv{pv}, pvMax{pv}, pa{pa}, niveau{niv} {
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

    void sauvegarder(std::ostream& fichier) const {
        fichier << pv << '\n';
    }

    bool charger(std::istream& fichier) {
        return (fichier >> pv) && pv > 0 && pv <= pvMax;
    }
};

int main() {
    constexpr unsigned int graine = 42;
    const std::string cheminSauvegarde = "workshop1-partie.txt";

    std::srand(graine);
    int toursJoues = 0;

    Heros heros{"Hrun", 10, 10};
    Creature creature{10, 10, 5};

    heros.affiche();
    creature.affiche();

    while (heros.estVivant() && creature.estVivant()) {
        std::cout << "\n1. Attaquer\n"
                  << "2. Quitter\n"
                  << "3. Equiper l'epee\n"
                  << "4. Boire la potion\n"
                  << "5. Sauvegarder\n"
                  << "6. Charger\n"
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

        if (choix == "5") {
            std::ofstream fichier{cheminSauvegarde};
            heros.sauvegarder(fichier);
            creature.sauvegarder(fichier);
            fichier << toursJoues << '\n';
            fichier.close();

            if (fichier) {
                std::cout << "Partie sauvegardee dans " << cheminSauvegarde << ".\n";
            } else {
                std::cout << "Impossible de sauvegarder la partie.\n";
            }
            continue;
        }

        if (choix == "6") {
            std::ifstream fichier{cheminSauvegarde};
            Heros herosCharge = heros;
            Creature creatureChargee = creature;
            int toursCharges = 0;

            // La creature commence a 10 PV et perd au moins 1 PV par tour.
            if (!herosCharge.charger(fichier)
                || !creatureChargee.charger(fichier)
                || !(fichier >> toursCharges)
                || toursCharges < 0 || toursCharges > 9) {
                std::cout << "Sauvegarde absente ou invalide.\n";
                continue;
            }

            heros = herosCharge;
            creature = creatureChargee;
            toursJoues = toursCharges;

            // Chaque tour termine avec les deux personnages vivants
            // a consomme deux tirages, un par attaque.
            std::srand(graine);
            for (int i = 0; i < 2 * toursJoues; ++i) {
                std::rand();
            }

            std::cout << "Partie chargee.\n";
            heros.affiche();
            creature.affiche();
            continue;
        }

        if (choix != "1") {
            std::cout << "Choix invalide. Saisis un nombre de 1 a 6.\n";
            continue;
        }

        const int degatsHeros = heros.attaque();
        creature.subitDegat(degatsHeros);
        std::cout << "Hrun inflige " << degatsHeros << " degats.\n";

        if (creature.estVivant()) {
            const int degatsCreature = creature.attaque();
            heros.subitDegat(degatsCreature);
            std::cout << "La creature inflige " << degatsCreature << " degats.\n";
            ++toursJoues;
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