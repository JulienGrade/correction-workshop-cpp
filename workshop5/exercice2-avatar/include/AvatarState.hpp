#pragma once

// Classe commune aux cinq états émotionnels.
class AvatarState {
private:
    // Adresse de l'état qui doit suivre celui-ci.
    // nullptr indiquera la fin du parcours.
    AvatarState* suivant;

public:
    // Chaque état reçoit son successeur lors de sa construction.
    explicit AvatarState(AvatarState* suivant) : suivant{suivant} {
    }

    virtual ~AvatarState() = default;

    // Chaque émotion doit fournir son propre affichage.
    // La méthode virtuelle pure rend AvatarState abstraite.
    virtual void action() const = 0;

    // Renvoie l'adresse du prochain état.
    // Cette implémentation commune convient aux cinq émotions.
    virtual AvatarState* next() const {
        return suivant;
    }
};