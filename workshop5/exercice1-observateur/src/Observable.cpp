#include "Observable.hpp"

// La définition complète d'Observer est nécessaire
// pour appeler sa méthode update().
#include "Observer.hpp"

// Fournit std::find pour chercher un élément dans un tableau.
#include <algorithm>

int Observable::subscribe(Observer* observer) {
    // Refuse un pointeur vide.
    if (observer == nullptr) {
        return -1;
    }

    // Cherche si cet objet est déjà inscrit.
    const auto position =
        std::find(observers.begin(), observers.end(), observer);

    // end() représente la position après le dernier élément.
    // Une autre position signifie que l'objet a été trouvé.
    if (position != observers.end()) {
        return -1;
    }

    // Ajoute l'adresse de l'observateur à la liste.
    observers.push_back(observer);

    // size() renvoie une taille que l'on convertit ici en int
    // pour conserver le type de retour proposé par le sujet.
    return static_cast<int>(observers.size());
}

int Observable::unsubscribe(Observer* observer) {
    // Recherche l'observateur à retirer.
    const auto position =
        std::find(observers.begin(), observers.end(), observer);

    // L'objet n'est pas inscrit.
    if (position == observers.end()) {
        return -1;
    }

    // Retire son adresse de la liste.
    // L'objet observateur lui-même continue d'exister.
    observers.erase(position);

    return static_cast<int>(observers.size());
}

void Observable::notify() {
    // Chaque pointeur désigne un observateur inscrit.
    for (Observer* observer : observers) {
        // this désigne l'objet observable qui envoie la notification.
        // La méthode virtuelle update() sélectionne la réaction
        // correspondant à l'observateur réel.
        observer->update(this);
    }
}