#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Room {
private:
    int nb_windows;
    std::string color;

public:
    Room(int nb_windows, const std::string& color)
        : nb_windows{nb_windows}, color{color} {
    }

    virtual ~Room() = default;
};

class Bathroom : public Room {
private:
    bool has_Shower;

public:
    Bathroom(int nb_windows, const std::string& color, bool has_Shower)
        : Room{nb_windows, color}, has_Shower{has_Shower} {
    }
};

class Bedroom : public Room {
private:
    int nb_beds;

public:
    Bedroom(int nb_windows, const std::string& color, int nb_beds)
        : Room{nb_windows, color}, nb_beds{nb_beds} {
    }
};

class House {
private:
    std::vector<std::unique_ptr<Room>> rooms;

public:
    explicit House(std::size_t nb_rooms) : rooms(nb_rooms) {
    }
};

int main() {
    Room salon{2, "blanc"};
    Bathroom salleDeBains{1, "bleu", true};
    Bedroom chambre{2, "vert", 1};
    House maison{3};

    std::cout << "Les trois types de pieces et la maison ont ete crees.\n";

    return 0;
}