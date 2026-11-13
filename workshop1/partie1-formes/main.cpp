#include <iostream>
#include <cmath>

typedef struct Circle {
    double x;
    double y;
    double r;
} Circle;

void set_pos(Circle* c, double x, double y) {
    c->x = x;
    c->y = y;
}

double perimeter(Circle c) {
    return 2 * M_PI * c.r;
}

// TODO: Add a method to calculate the area of the circle

typedef struct Rectangle {
    double x;
    double y;
    double w;
    double h;
} Rectangle;

// TODO: Add a method to calculate the area of the rectangle

void set_pos(Rectangle* r, double x, double y) {
    r->x = x;
    r->y = y;
}

double perimeter(Rectangle r) {
    return 2 * (r.w + r.h);
}

int main() {
    Circle c{0, 0, 1};
    std::cout << perimeter(c) << std::endl;
    set_pos(&c, 1, 1);
    std::cout << "Coordinates of the center: ("
              << c.x << ", " << c.y << ")" << std::endl;

    Rectangle r{0, 0, 1, 2};
    std::cout << perimeter(r) << std::endl;
    set_pos(&r, -1, -1);
    std::cout << "Coordinates of the top left corner: ("
              << r.x << ", " << r.y << ")" << std::endl;

    return 0;
}