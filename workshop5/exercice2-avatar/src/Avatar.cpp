#include "Avatar.hpp"

// Fournit std::chrono::seconds pour exprimer une durée.
#include <chrono>

// Fournit std::this_thread::sleep_for pour effectuer une pause.
#include <thread>

Avatar::Avatar(AvatarState& premierEtat) : state{&premierEtat} {
}

void Avatar::run() {
    // Continue tant qu'un état courant existe.
    while (state != nullptr) {
        // Appelle la version de action() correspondant
        // à l'émotion réellement pointée.
        state->action();

        // Demande à cet état quel objet doit lui succéder.
        AvatarState* prochainEtat = state->next();

        // Attend uniquement s'il reste une transition à effectuer.
        if (prochainEtat != nullptr) {
            std::this_thread::sleep_for(std::chrono::seconds{5});
        }

        // Fait pointer l'avatar vers l'émotion suivante.
        // Si prochainEtat vaut nullptr, la boucle se terminera.
        state = prochainEtat;
    }
}