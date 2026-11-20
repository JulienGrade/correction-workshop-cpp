#pragma once

// Annonce que la classe Observable existe.
// Un pointeur vers cette classe peut alors être déclaré
// sans inclure son en-tête ici.
class Observable;

// Interface commune à tous les observateurs.
class Observer {
public:
    virtual ~Observer() = default;

    // L'observable appelle cette méthode pour signaler un événement.
    // Chaque observateur fournit sa propre réaction.
    // observed indique quel objet a envoyé la notification.
    virtual void update(Observable* observed) = 0;
};