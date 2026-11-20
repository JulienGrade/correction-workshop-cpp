#pragma once

#include "AvatarState.hpp"

// Les cinq classes sont regroupées dans cet en-tête
// car elles représentent la même famille d'états.

class Glad : public AvatarState {
public:
    // Transmet l'état suivant au constructeur de la classe de base.
    explicit Glad(AvatarState* suivant) : AvatarState{suivant} {
    }

    void action() const override;
};

class Happy : public AvatarState {
public:
    explicit Happy(AvatarState* suivant) : AvatarState{suivant} {
    }

    void action() const override;
};

class Sad : public AvatarState {
public:
    explicit Sad(AvatarState* suivant) : AvatarState{suivant} {
    }

    void action() const override;
};

class Angry : public AvatarState {
public:
    explicit Angry(AvatarState* suivant) : AvatarState{suivant} {
    }

    void action() const override;
};

class Grumpy : public AvatarState {
public:
    explicit Grumpy(AvatarState* suivant) : AvatarState{suivant} {
    }

    void action() const override;
};