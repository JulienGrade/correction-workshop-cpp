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

    void affiche() const;
    int attaque() const;
    void subitDegat(int degat);
    bool estVivant() const;
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

    void affiche() const;
    int attaque() const;
    void subitDegat(int degat);
    bool estVivant() const;
};

int main() {
    Heros heros{"Hrun", 10, 10};
    Creature creature{10, 10, 5};

    std::cout << "Le heros et la creature ont ete crees.\n";

    return 0;
}