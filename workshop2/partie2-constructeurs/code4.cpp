#include <iostream>

using namespace std;

class Creature {
public:
    Creature() {}

    Creature(const Creature&) {
        cout << "A creature has been duplicated" << endl;
    }

    ~Creature() {
        cout << "A Creature has been destroyed" << endl;
    }
};

Creature foo(Creature& c) {
    cout << "foo" << endl;
    Creature local = c;
    return c;
}

int main() {
    Creature ogre;

    cout << "before foo" << endl;
    Creature shrek = foo(ogre);
    cout << "after foo" << endl;

    return 0;
}