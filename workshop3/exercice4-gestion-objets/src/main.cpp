#include "Carre.hpp"
#include "GestionObjets.hpp"
#include "Rectangle.hpp"

#include <iostream>
#include <memory>
#include <utility>

int main() {
    GestionObjets gestion{2};

    auto carre = std::make_unique<Carre>(4);
    auto rectangle = std::make_unique<Rectangle>(3, 5);

    if (!gestion.ajouterObjet(std::move(carre), 1)) {
        std::cerr << "Impossible d'ajouter le carre a l'index 1.\n";
        return 1;
    }

    if (!gestion.ajouterObjet(std::move(rectangle))) {
        std::cerr << "Impossible d'ajouter le rectangle.\n";
        return 1;
    }

    gestion.afficherInfos();

    return 0;
}