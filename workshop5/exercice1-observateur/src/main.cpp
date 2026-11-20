#include "ConcreteObservable.hpp"
#include "ConcreteObservers.hpp"

#include <iostream>

int main() {
    // Les observateurs sont créés avant l'observable.
    // Ils resteront donc vivants pendant toute son utilisation.
    ConcreteObservers observateur1{"Toto"};
    ConcreteObservers observateur2{"Tata"};

    ConcreteObservable observable;

    // & donne l'adresse des objets à inscrire.
    observable.subscribe(&observateur1);
    observable.subscribe(&observateur2);

    std::cout << "Premier evenement :\n";

    // Les deux observateurs sont inscrits.
    observable.someEvent();

    // Toto est retiré de la liste des destinataires.
    observable.unsubscribe(&observateur1);

    std::cout << "\nDeuxieme evenement :\n";

    // Seul Tata reçoit cette notification.
    observable.someEvent();

    // Un second retrait de Toto est refusé.
    const int resultat = observable.unsubscribe(&observateur1);

    std::cout << "\nSecond retrait de Toto : "
              << resultat << '\n';

    return 0;
}