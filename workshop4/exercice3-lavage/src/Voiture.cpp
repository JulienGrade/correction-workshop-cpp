// Rend la déclaration de Voiture accessible dans ce fichier.
#include "Voiture.hpp"

// Fournit std::cout pour l'affichage.
#include <iostream>

// Voiture:: indique que cette méthode appartient à Voiture.
void Voiture::laver() const {
    // Le lavage est représenté par un message dans le Terminal.
    std::cout << "Voiture lavée\n";
}