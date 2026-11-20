#pragma once

#include "coordinate.hpp"

// Fournit les fonctions mathématiques, dont std::hypot.
#include <cmath>

// Regroupe les éléments liés à la géométrie.
namespace geometry {

// Le nom complet de cette classe est geometry::Vector.
class Vector {
public:
    float x;
    float y;

    // Initialise directement les coordonnées.
    Vector(float x, float y) : x{x}, y{y} {
    }

    float getMagnitude() const {
        // Calcule la norme : racine carrée de x² + y².
        // Pour x = 3 et y = 4, le résultat vaut 5.
        return std::hypot(x, y);
    }

    Coordinate getPosition() const {
        // Crée et renvoie une structure contenant les coordonnées.
        return {x, y};
    }
};

}