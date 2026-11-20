#pragma once

#include "Observable.hpp"

// Exemple concret d'un objet qui peut être observé.
class ConcreteObservable : public Observable {
public:
    // Simule un événement produit par cet objet.
    void someEvent() {
        // Utilise la méthode protégée héritée d'Observable.
        notify();
    }
};