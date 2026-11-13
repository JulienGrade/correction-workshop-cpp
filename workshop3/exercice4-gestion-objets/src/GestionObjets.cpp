#include "GestionObjets.hpp"

#include <utility>

GestionObjets::GestionObjets(std::size_t capacite) : objets(capacite) {
}

bool GestionObjets::ajouterObjet(std::unique_ptr<Objet> objet) {
    for (std::size_t index = 0; index < objets.size(); ++index) {
        if (!objets[index]) {
            return ajouterObjet(std::move(objet), index);
        }
    }

    return false;
}

bool GestionObjets::ajouterObjet(std::unique_ptr<Objet> objet, std::size_t index) {
    if (!objet || index >= objets.size() || objets[index]) {
        return false;
    }

    objets[index] = std::move(objet);
    return true;
}

void GestionObjets::afficherInfos() const {
    for (const auto& objet : objets) {
        if (objet) {
            objet->afficheInfo();
        }
    }
}