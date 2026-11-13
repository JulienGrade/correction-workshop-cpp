#include <iostream>

class Creature {
private:
    int pv{10};
    int pa{10};
    int niveau{1};

public:
    inline static int cpt{0};

    Creature() {
        ++cpt;
    }

    Creature(int pv, int pa, int niv)
        : pv{pv}, pa{pa}, niveau{niv} {
        ++cpt;
    }

    ~Creature() {
        --cpt;
    }

    void affiche() const {
        std::cout << "Creature niveau " << niveau << " - "
                  << pv << " PV, " << pa << " PA\n";
    }
};

int main() {
    std::cout << "Avant le bloc : " << Creature::cpt << '\n';

    {
        Creature c1;
        Creature c2{10, 2, 2};

        c1.affiche();
        c2.affiche();
        std::cout << "Dans le bloc : " << Creature::cpt << '\n';
    }

    std::cout << "Apres le bloc : " << Creature::cpt << '\n';

    return 0;
}