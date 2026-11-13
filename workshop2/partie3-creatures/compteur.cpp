#include <iostream>

using std::cout;
using std::endl;

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

    Creature(const Creature& autre)
        : pv{autre.pv}, pa{autre.pa}, niveau{autre.niveau} {
        ++cpt;
    }

    ~Creature() {
        --cpt;
    }

    void affiche() const {
        cout << "Creature niveau " << niveau << " - "
             << pv << " PV, " << pa << " PA\n";
    }
};

void foo() {
    Creature c3;
    cout << "Nombre de créatures: " << Creature::cpt << endl;
}

void test1() {
    cout << "Test 1: \n";
    Creature c1;
    Creature c2(10, 2, 2);
    cout << "Nombre de créatures: " << Creature::cpt << endl;
    foo();
    cout << "Nombre de créatures: " << Creature::cpt << endl;
}

void bar(Creature) {
    Creature c2;
    cout << "Nombre de créatures: " << Creature::cpt << endl;
}

void test2() {
    cout << "Test 2: \n";
    Creature c1;
    Creature c2(10, 2, 2);
    cout << "Nombre de créatures: " << Creature::cpt << endl;
    bar(c2);
    cout << "Nombre de créatures: " << Creature::cpt << endl;
}

int main() {
    test1();
    test2();
    cout << "Après les tests: " << Creature::cpt << '\n';

    return 0;
}