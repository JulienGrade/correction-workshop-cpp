// Donne accès à la déclaration de la classe Saxophone.
#include "Saxophone.hpp"

// Fournit std::cout pour écrire dans le Terminal.
#include <iostream>

// Saxophone:: indique à quelle classe cette méthode appartient.
// Le const correspond à celui de la déclaration dans l'en-tête.
void Saxophone::jouer() const {
    // Représente le son du saxophone par un message.
    std::cout << "Le saxophone joue : Pouet pouet !\n";
}