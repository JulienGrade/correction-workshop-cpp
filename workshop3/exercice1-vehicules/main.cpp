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
    }

    int getseating_capacity() const {
        return seat_capacity;
    }

    void setseating_capacity(int capacity) {
        if (capacity < 10 || capacity > 50) {
            capacity = 50;
        }
        seat_capacity = capacity;
    }
};

int main() {
    Bus bus;

    std::cout << "Capacite initiale : "
              << bus.getseating_capacity() << " places\n";

    for (int capacity : {10, 40, 50, 9, 51}) {
        bus.setseating_capacity(capacity);
        std::cout << "Demande de " << capacity << " places -> "
                  << bus.getseating_capacity() << " places\n";
    }

    return 0;
}