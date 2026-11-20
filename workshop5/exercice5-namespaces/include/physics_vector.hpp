#pragma once

#include "coordinate.hpp"

// Fournit std::cos et std::sin.
#include <cmath>

// Regroupe les éléments liés à la physique.
namespace physics {

// Le nom complet de cette classe est physics::Vector.
// Elle peut coexister avec geometry::Vector.
class Vector {
public:
    // Longueur du vecteur.
    float magnitude;

    // Angle exprimé en radians.
    float angle;

    Vector(float magnitude, float angle)
        : magnitude{magnitude}, angle{angle} {
    }

    float getMagnitude() const {
        // La norme est déjà stockée dans l'objet.
        return magnitude;
    }

    Coordinate getPosition() const {
        // Transforme la norme et l'angle en coordonnées.
        // x = norme × cos(angle)
        // y = norme × sin(angle)
        return {
            magnitude * std::cos(angle),
            magnitude * std::sin(angle)
        };
    }
};

}