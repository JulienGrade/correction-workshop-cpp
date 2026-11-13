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

void foo(Creature) {
    cout << "foo" << endl;
}

int main() {
    Creature ogre;
    Creature shrek = ogre;

    cout << "before foo" << endl;
    foo(shrek);
    cout << "after foo" << endl;

    return 0;
}