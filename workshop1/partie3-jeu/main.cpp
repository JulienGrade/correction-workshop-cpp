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

    const int degatsHeros = heros.attaque();
    const int degatsCreature = creature.attaque();

    if (degatsHeros < 1 || degatsHeros > 10 ||
        degatsCreature < 1 || degatsCreature > 10) {
        std::cerr << "[ECHEC] Degats hors limites.\n";
        return 1;
    }
    std::cout << "[OK] Les deux attaques donnent entre 1 et 10 degats.\n";

    heros.subitDegat(3);
    creature.subitDegat(10);

    heros.affiche();
    creature.affiche();

    if (!heros.estVivant() || creature.estVivant()) {
        std::cerr << "[ECHEC] Etat des personnages incorrect.\n";
        return 1;
    }
    std::cout << "[OK] Le heros est vivant et la creature est vaincue.\n";

    return 0;
}