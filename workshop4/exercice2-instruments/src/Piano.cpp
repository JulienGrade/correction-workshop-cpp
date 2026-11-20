#include "Piano.hpp"

#include <iostream>

// Implémentation de la méthode déclarée dans Piano.hpp.
void Piano::jouer() const {
    // Le même nom de méthode produit ici le son du piano.
    std::cout << "Le piano joue : Do re mi !\n";
}