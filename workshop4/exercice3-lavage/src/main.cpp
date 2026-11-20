// Rend les classes utilisables dans le programme principal.
#include "Moto.hpp"
#include "StationLavage.hpp"
#include "Voiture.hpp"

#include <iostream>
#include <memory>
#include <utility>

int main() {
    // Crée une station dont le parc est initialement vide.
    StationLavage station;

    // make_unique crée chaque objet et renvoie son pointeur intelligent.
    // auto laisse le compilateur déduire les types des variables.
    auto voiture1 = std::make_unique<Voiture>();
    auto voiture2 = std::make_unique<Voiture>();
    auto moto = std::make_unique<Moto>();

    // Transfère chaque véhicule à la station.
    // Après ces appels, les trois variables locales sont vides.
    // La station possède désormais les trois objets.
    station.ajouterVehicule(std::move(voiture1));
    station.ajouterVehicule(std::move(voiture2));
    station.ajouterVehicule(std::move(moto));

    // Les emplacements contiennent, dans l'ordre :
    // index 0 : première voiture
    // index 1 : deuxième voiture
    // index 2 : moto
    std::cout << "Premier lavage :\n";
    station.laverTous();

    // Crée une nouvelle moto pour remplacer la première voiture.
    // Le type de l'ancien objet reste Voiture jusqu'à sa destruction.
    // C'est le contenu de l'emplacement qui change.
    // ! inverse le résultat : on entre dans le if en cas d'échec.
    if (!station.remplacerVehicule(0, std::make_unique<Moto>())) {
        // cerr affiche un message d'erreur.
        std::cerr << "Impossible de remplacer le premier vehicule.\n";

        // Termine le programme avec un code d'erreur.
        return 1;
    }

    // Le parc contient maintenant une moto, une voiture et une moto.
    std::cout << "\nApres remplacement de la premiere voiture par une moto :\n";

    // On utilise exactement le même appel pour laver le nouveau parc.
    // Le polymorphisme sélectionne le lavage de chaque véhicule.
    station.laverTous();

    // À la sortie de main, la station est détruite.
    // Son vector détruit les unique_ptr, qui détruisent les véhicules.
    return 0;
}