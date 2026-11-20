#include "ConcreteObservers.hpp"

#include <iostream>

// Initialise le nom au moment de la création de l'observateur.
ConcreteObservers::ConcreteObservers(const std::string& name)
    : name{name} {
}

void ConcreteObservers::update(Observable* observed) {
    // Le paramètre donne accès à l'objet émetteur.
    // Cet exemple affiche seulement la réception de l'événement.
    if (observed != nullptr) {
        std::cout << name << " a recu une notification.\n";
    }
}