#pragma once

#include "Observer.hpp"

#include <string>

// Observateur concret qui affiche une notification.
class ConcreteObservers : public Observer {
private:
    // Permet de distinguer les observateurs dans le Terminal.
    std::string name;

public:
    explicit ConcreteObservers(const std::string& name);

    // Implémente la réaction imposée par Observer.
    void update(Observable* observed) override;
};