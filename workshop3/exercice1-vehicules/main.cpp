#include <iostream>

class Vehicule {
private:
    int max_speed;
    int mileage;

public:
    Vehicule() : max_speed{240}, mileage{0} {
    }
};

int main() {
    Vehicule vehicule;
    std::cout << "Vehicule cree.\n";

    return 0;
}