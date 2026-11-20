#include "StationLavage.hpp"

// Fournit std::move pour transférer la propriété des véhicules.
#include <utility>

void StationLavage::ajouterVehicule(std::unique_ptr<Vehicule> vehicule) {
    // Un unique_ptr vide ne possède aucun véhicule.
    // On ajoute uniquement les pointeurs qui possèdent un objet.
    if (vehicule) {
        // push_back ajoute un emplacement à la fin du tableau.
        // std::move permet de transférer la propriété du véhicule
        // depuis le paramètre vers cet emplacement.
        vehicules.push_back(std::move(vehicule));
    }
}

bool StationLavage::remplacerVehicule(
    std::size_t index,
    std::unique_ptr<Vehicule> vehicule
) {
    // size() donne le nombre de véhicules présents.
    // Les index valides vont de 0 à size() - 1.
    // !vehicule vérifie si le pointeur reçu est vide.
    if (index >= vehicules.size() || !vehicule) {
        // Le parc reste intact si le remplacement est impossible.
        // Le paramètre possède le nouvel objet :
        // cet objet sera détruit à la sortie de la méthode.
        return false;
    }

    // Détruit l'ancien véhicule de cet emplacement,
    // puis y transfère la propriété du nouveau véhicule.
    vehicules[index] = std::move(vehicule);

    // Confirme que le remplacement a réussi.
    return true;
}

void StationLavage::laverTous() const {
    // Parcourt les véhicules dans leur ordre d'ajout.
    // const auto& accède à chaque unique_ptr par référence constante.
    // Cela évite de chercher à copier un unique_ptr.
    for (const auto& vehicule : vehicules) {
        // -> appelle une méthode sur l'objet pointé.
        // laver() est virtuelle : C++ choisit la version
        // de Voiture ou de Moto selon l'objet réellement stocké.
        vehicule->laver();
    }
}