#include <cstdlib>
#include <iostream>
#include <string>

class Heros {
private:
    std::string nom{"Heros"};
    int pv{10};
    int pa{10};

public:
    Heros() = default;

    Heros(std::string nom, int pv, int pa)
        : nom{nom}, pv{pv}, pa{pa} {
    }

    void affiche() const {
        std::cout << nom << " - " << pv << " PV, " << pa << " PA\n";
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
        std::cout << "\n1. Attaquer\n2. Quitter\nTon choix : ";

        std::string choix;
        if (!std::getline(std::cin, choix) || choix == "2") {
            std::cout << "Partie terminee.\n";
            return 0;
        }

        if (choix != "1") {
            std::cout << "Choix invalide. Saisis 1 ou 2.\n";
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