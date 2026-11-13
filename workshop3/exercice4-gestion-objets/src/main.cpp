#include "GestionObjets.hpp"

#include <iostream>

int main() {
    GestionObjets gestion{2};

    std::cout << "Collection vide creee.\n";
    gestion.afficherInfos();

    return 0;
}