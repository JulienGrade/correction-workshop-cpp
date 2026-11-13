#include <cstddef>
#include <iostream>
#include <memory>
#include <string>
#include <utility>
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

    int getNbWindows() const {
        return nb_windows;
    }

    void setNbWindows(int nb_windows) {
        this->nb_windows = nb_windows;
    }

    const std::string& getColor() const {
        return color;
    }

    void setColor(const std::string& color) {
        this->color = color;
    }
};

class Bathroom : public Room {
private:
    bool has_Shower;

public:
    Bathroom(int nb_windows, const std::string& color, bool has_Shower)
        : Room{nb_windows, color}, has_Shower{has_Shower} {
    }

    bool getHasShower() const {
        return has_Shower;
    }

    void setHasShower(bool has_Shower) {
        this->has_Shower = has_Shower;
    }
};

class Bedroom : public Room {
private:
    int nb_beds;

public:
    Bedroom(int nb_windows, const std::string& color, int nb_beds)
        : Room{nb_windows, color}, nb_beds{nb_beds} {
    }

    int getNbBeds() const {
        return nb_beds;
    }

    void setNbBeds(int nb_beds) {
        this->nb_beds = nb_beds;
    }
};

class House {
private:
    std::vector<std::unique_ptr<Room>> rooms;

public:
    explicit House(std::size_t nb_rooms) : rooms(nb_rooms) {
    }

    const Room* getRoom(std::size_t index) const {
        return rooms.at(index).get();
    }

    void setRoom(std::size_t index, std::unique_ptr<Room> room) {
        rooms.at(index) = std::move(room);
    }

    void getNbOfBathroom() const {
        int count = 0;

        for (const auto& room : rooms) {
            if (dynamic_cast<const Bathroom*>(room.get()) != nullptr) {
                ++count;
            }
        }

        std::cout << "Nombre de salles de bains : " << count << '\n';
    }

    void getNbOfBedroom() const {
        int count = 0;

        for (const auto& room : rooms) {
            if (dynamic_cast<const Bedroom*>(room.get()) != nullptr) {
                ++count;
            }
        }

        std::cout << "Nombre de chambres : " << count << '\n';
    }
};

int main() {
    House maison{5};

    maison.setRoom(0, std::make_unique<Room>(3, "gris"));
    maison.setRoom(1, std::make_unique<Bathroom>(1, "bleu", true));
    maison.setRoom(2, std::make_unique<Bedroom>(2, "vert", 2));
    maison.setRoom(3, std::make_unique<Bedroom>(1, "blanc", 1));

    maison.getNbOfBathroom();
    maison.getNbOfBedroom();

    return 0;
}