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

int main() {
    Vehicule vehicule;

    std::cout << "Valeurs initiales : "
              << vehicule.getmax_speed() << " km/h, "
              << vehicule.getmileage() << " km\n";

    vehicule.setmax_speed(200);
    vehicule.setmileage(1500);
    std::cout << "Apres des valeurs valides : "
              << vehicule.getmax_speed() << " km/h, "
              << vehicule.getmileage() << " km\n";

    vehicule.setmax_speed(199);
    vehicule.setmileage(-10);
    std::cout << "Apres des valeurs hors limites : "
              << vehicule.getmax_speed() << " km/h, "
              << vehicule.getmileage() << " km\n";

    return 0;
}