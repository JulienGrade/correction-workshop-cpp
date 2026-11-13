#include <iostream>
#include <iterator>
#include <string>

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

    void get_info() const {
        std::cout << "Il s'agit d'un bus d'une capacité de "
                  << getseating_capacity()
                  << " places, avec une vitesse maximale de "
                  << getmax_speed()
                  << " km/h et son kilométrage est de "
                  << getmileage() << " km.\n";
    }
};

class SchoolBus : public Bus {
private:
    std::string school_name;

public:
    SchoolBus(std::string sn) : school_name{sn} {
    }

    std::string getSchoolName() const {
        return school_name;
    }

    void setSchoolName(std::string sn) {
        school_name = sn;
    }
};

static int countbigbus(const SchoolBus t[], std::size_t taille) {
    int nombre = 0;

    for (std::size_t i = 0; i < taille; ++i) {
        if (t[i].getseating_capacity() >= 40 && t[i].getmileage() < 200000) {
            ++nombre;
        }
    }

    return nombre;
}

int main() {
    SchoolBus busScolaires[] = {
        SchoolBus{"École A"},
        SchoolBus{"École B"},
        SchoolBus{"École C"},
        SchoolBus{"École D"}
    };

    busScolaires[0].setseating_capacity(40);
    busScolaires[0].setmileage(199999);

    busScolaires[1].setseating_capacity(50);
    busScolaires[1].setmileage(200000);

    busScolaires[2].setseating_capacity(39);
    busScolaires[2].setmileage(150000);

    busScolaires[3].setseating_capacity(45);
    busScolaires[3].setmileage(120000);

    for (const SchoolBus& bus : busScolaires) {
        std::cout << bus.getSchoolName() << " - "
                  << bus.getseating_capacity() << " places, "
                  << bus.getmileage() << " km\n";
    }

    std::cout << "Nombre de grands bus scolaires : "
              << countbigbus(busScolaires, std::size(busScolaires)) << '\n';

    return 0;
}