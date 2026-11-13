#include <cassert>
#include <iostream>

class Vehicule {
private:
    int max_speed;
    int mileage;

public:
    Vehicule() : max_speed{240}, mileage{0} {
    }

    void setmax_speed(int speed) {
        if (speed < 200) {
            speed = 240;
        }
        max_speed = speed;
    }

    int getmax_speed() const {
        return max_speed;
    }

    void setmileage(int distance) {
        if (distance < 0) {
            distance = 0;
        }
        mileage = distance;
    }

    int getmileage() const {
        return mileage;
    }
};

class Bus : public Vehicule {
private:
    int seat_capacity;

public:
    Bus() : seat_capacity{10} {
        assert(seat_capacity == 10);
    }
};

int main() {
    Bus bus;

    std::cout << "Bus au depart : "
              << bus.getmax_speed() << " km/h, "
              << bus.getmileage() << " km\n";

    bus.setmileage(1500);
    std::cout << "Bus apres modification : "
              << bus.getmileage() << " km\n";

    return 0;
}