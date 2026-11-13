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

void bar(Creature* c) {
    cout << "bar" << endl;
    delete c;
}

int main() {
    Creature ogre;
    Creature* shrek = new Creature(ogre);

    cout << "before bar" << endl;
    bar(shrek);
    cout << "after bar" << endl;

    return 0;
}