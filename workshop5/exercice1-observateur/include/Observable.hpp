#pragma once

#include <vector>

// La classe utilise des pointeurs Observer*.
// Une déclaration anticipée suffit dans cet en-tête.
class Observer;

class Observable {
private:
    // Liste des observateurs inscrits.
    // Ces pointeurs permettent de contacter les objets.
    // Leur durée de vie est gérée par le code qui les crée.
    std::vector<Observer*> observers;

protected:
    // Les classes dérivées déclencheront les notifications
    // lorsqu'un événement se produira.
    void notify();

public:
    virtual ~Observable() = default;

    // Inscrit un observateur.
    // Renvoie le nombre d'inscrits, ou -1 si l'inscription est refusée.
    int subscribe(Observer* observer);

    // Retire un observateur.
    // Renvoie le nombre restant, ou -1 si l'objet était absent.
    int unsubscribe(Observer* observer);
};