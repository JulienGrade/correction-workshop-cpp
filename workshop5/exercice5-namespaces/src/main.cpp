// Les deux en-têtes déclarent une classe appelée Vector.
// Leurs namespaces permettent de les utiliser ensemble.
#include "geometry_vector.hpp"
#include "physics_vector.hpp"

// Fournit assert pour vérifier les résultats.
#include <cassert>

// Fournit std::fabs pour calculer une valeur absolue.
#include <cmath>

#include <iostream>

// Fournit la constante pi en C++20.
#include <numbers>

void test() {
    // Les calculs avec des nombres flottants sont approximatifs.
    // On accepte ici un écart inférieur à 0,00001.
    constexpr float tolerance = 0.00001f;

    // :: précise dans quel namespace chercher la classe.
    geometry::Vector geometrie{3.0f, 4.0f};

    // Récupère les coordonnées du vecteur.
    const Coordinate positionGeometrie = geometrie.getPosition();

    // Vérifie la norme et les coordonnées.
    // Une assertion fausse arrête le programme.
    assert(std::fabs(geometrie.getMagnitude() - 5.0f) < tolerance);
    assert(std::fabs(positionGeometrie.x - 3.0f) < tolerance);
    assert(std::fabs(positionGeometrie.y - 4.0f) < tolerance);

    std::cout
        << "[OK] geometry::Vector : position (3, 4), norme 5\n";

    // pi radians correspondent à un demi-tour.
    // Avec une norme de 10, la position attendue est proche de (-10, 0).
    physics::Vector physique{10.0f, std::numbers::pi_v<float>};

    const Coordinate positionPhysique = physique.getPosition();

    assert(std::fabs(physique.getMagnitude() - 10.0f) < tolerance);
    assert(std::fabs(positionPhysique.x - (-10.0f)) < tolerance);
    assert(std::fabs(positionPhysique.y) < tolerance);

    std::cout
        << "[OK] physics::Vector : position proche de (-10, 0), norme 10\n";
}

int main() {
    // Exécute les deux séries de vérifications.
    test();

    return 0;
}