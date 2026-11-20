#include "Emotions.hpp"

#include <iostream>

// Chaque méthode affiche l'émotion correspondant à sa classe.
// std::endl passe à la ligne et force l'affichage immédiatement,
// avant la pause de cinq secondes.

void Glad::action() const {
    std::cout << "Glad : heureux :-D" << std::endl;
}

void Happy::action() const {
    std::cout << "Happy : joyeux :-)" << std::endl;
}

void Sad::action() const {
    std::cout << "Sad : triste :-(" << std::endl;
}

void Angry::action() const {
    std::cout << "Angry : en colere >:(" << std::endl;
}

void Grumpy::action() const {
    std::cout << "Grumpy : ronchon :-/" << std::endl;
}