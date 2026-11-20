#pragma once

#include "AvatarState.hpp"

class Avatar {
private:
    // Pointe vers l'émotion actuellement utilisée.
    // L'avatar consulte les états créés dans main.
    AvatarState* state;

public:
    // Reçoit le premier état par référence.
    // Cela garantit qu'un état de départ est fourni.
    explicit Avatar(AvatarState& premierEtat);

    // Parcourt les états jusqu'à la fin de la chaîne.
    void run();
};