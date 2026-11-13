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

void foo(Creature& c) {
    cout << "foo" << endl;
    Creature a = c;
}

int main() {
    Creature ogre;

    cout << "before foo" << endl;
    foo(ogre);
    cout << "after foo" << endl;

    return 0;
}