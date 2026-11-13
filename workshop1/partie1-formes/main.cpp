#include <iostream>
#include <cmath>

class Circle {
public:
    double x;
    double y;
    double r;

    Circle(double x, double y, double r)
        : x{x}, y{y}, r{r} {
    }

    void set_pos(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double perimeter() const {
        return 2 * M_PI * r;
    }

    // TODO: Add a method to calculate the area of the circle
};

class Rectangle {
public:
    double x;
    double y;
    double w;
    double h;

    Rectangle(double x, double y, double w, double h)
        : x{x}, y{y}, w{w}, h{h} {
    }

    void set_pos(double x, double y) {
        this->x = x;
        this->y = y;
    }

    double perimeter() const {
        return 2 * (w + h);
    }

    // TODO: Add a method to calculate the area of the rectangle
};

int main() {
    Circle c{0, 0, 1};
    std::cout << c.perimeter() << std::endl;
    c.set_pos(1, 1);
    std::cout << "Coordinates of the center: ("
              << c.x << ", " << c.y << ")" << std::endl;

    Rectangle r{0, 0, 1, 2};
    std::cout << r.perimeter() << std::endl;
    r.set_pos(-1, -1);
    std::cout << "Coordinates of the top left corner: ("
              << r.x << ", " << r.y << ")" << std::endl;

    return 0;
}