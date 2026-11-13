#pragma once

#include "Objet.hpp"

#include <cstddef>
#include <memory>
#include <vector>

class GestionObjets {
private:
    std::vector<std::unique_ptr<Objet>> objets;

public:
    explicit GestionObjets(std::size_t capacite);

    bool ajouterObjet(std::unique_ptr<Objet> objet);
    bool ajouterObjet(std::unique_ptr<Objet> objet, std::size_t index);
    void afficherInfos() const;
};