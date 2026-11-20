// Rend les deux classes utilisables dans ce fichier.
#include "Voiture.hpp"
#include "VoitureSport.hpp"

#include <iostream>

// Fournit std::unique_ptr et std::make_unique.
#include <memory>

// Reçoit une voiture par référence constante.
// La fonction peut lire l'objet, sans créer de copie.
// Elle accepte aussi une VoitureSport grâce à l'héritage.
void afficher(const Voiture& voiture) {
    // getType() est virtuelle :
    // la version appelée dépend du type réel de l'objet.
    std::cout << voiture.getType()
              << " : " << voiture.getVitesse() << " km/h"
              << ", maximum " << voiture.getVitesseMax()
              << ", acceleration " << voiture.getAcceleration()
              << '\n';
}

int main() {
    // Crée une voiture classique avec un maximum de 10
    // et une accélération de 3 pour obtenir un affichage court.
    // unique_ptr possède l'objet et gère sa destruction.
    std::unique_ptr<Voiture> voiture =
        std::make_unique<Voiture>(10, 3);

    // Crée directement une sportive locale.
    // Elle sera détruite automatiquement à la fin de main.
    VoitureSport sportive{20, 8};

    std::cout << "Au depart :\n";

    // *voiture donne accès à l'objet pointé
    // pour le transmettre à afficher par référence.
    afficher(*voiture);
    afficher(sportive);

    std::cout << "\nAcceleration de la voiture classique :\n";

    // -> appelle une méthode sur l'objet pointé.
    // L'objet est actuellement une voiture classique.
    voiture->accelerer();

    std::cout << "\nAcceleration de la sportive :\n";

    // . appelle une méthode sur un objet utilisé directement.
    sportive.accelerer();

    // Crée une nouvelle sportive et la confie au même unique_ptr.
    // L'ancienne voiture classique est détruite automatiquement.
    // Le nouvel objet commence à une vitesse de zéro.
    voiture = std::make_unique<VoitureSport>(20, 8);

    std::cout << "\nApres remplacement par une sportive :\n";
    afficher(*voiture);

    std::cout << "\nAcceleration via le pointeur Voiture :\n";

    // Le pointeur est toujours déclaré avec le type Voiture.
    // Comme accelerer() est virtuelle et que l'objet est une sportive,
    // C++ appelle maintenant VoitureSport::accelerer().
    voiture->accelerer();

    std::cout << "\nNouvel appel sur la sportive deja au maximum :\n";

    // Le message du mode sport apparaît.
    // La boucle de progression ne démarre plus :
    // la sportive a déjà atteint sa vitesse maximale.
    sportive.accelerer();
    afficher(sportive);

    // Trois objets ont été créés au total :
    // la classique, la sportive locale et la sportive de remplacement.
    std::cout << "\nNombre d'objets crees : "
              << Voiture::getNombreObjetsCrees() << '\n';

    // Signale au système que le programme s'est terminé correctement.
    return 0;
}