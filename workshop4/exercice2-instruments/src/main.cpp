// Rend les déclarations des classes accessibles dans ce fichier.
#include "Instrument.hpp"
#include "Piano.hpp"
#include "Saxophone.hpp"

// Fournit std::cout et std::cin.
#include <iostream>

// Fournit std::unique_ptr et std::make_unique.
#include <memory>

// Fournit std::string et std::getline.
#include <string>

int main() {
    // Présente les deux instruments disponibles.
    std::cout << "De quel instrument veux-tu jouer ?\n"
              << "1. Saxophone\n"
              << "2. Piano\n"
              << "Ton choix : ";

    // Stocke la ligne saisie au clavier.
    std::string choix;

    // Lit la saisie jusqu'à la touche Entrée.
    // Si la lecture échoue ou que l'entrée est fermée,
    // on termine le programme.
    if (!std::getline(std::cin, choix)) {
        return 0;
    }

    // Crée un pointeur intelligent initialement vide.
    // Aucun instrument n'est encore construit.
    // Il pourra gérer un objet dérivé de la classe Instrument.
    std::unique_ptr<Instrument> instrument;

    // Construit uniquement l'instrument choisi.
    if (choix == "1") {
        // Crée un Saxophone et transfère sa propriété au unique_ptr.
        instrument = std::make_unique<Saxophone>();
    } else if (choix == "2") {
        // Crée un Piano. Aucun Saxophone n'est créé dans cette branche.
        instrument = std::make_unique<Piano>();
    } else {
        // Une saisie différente de 1 ou 2 termine le programme.
        std::cout << "Choix invalide.\n";

        // Le code 1 signale que l'exécution n'a pas abouti normalement.
        return 1;
    }

    // -> appelle jouer() sur l'objet géré par le pointeur.
    // Comme jouer() est virtuelle, C++ sélectionne la version
    // de Saxophone ou de Piano selon l'objet réellement créé.
    // C'est le polymorphisme.
    instrument->jouer();

    // À la sortie de main, unique_ptr détruit automatiquement
    // l'instrument. Le destructeur virtuel permet d'appeler
    // la chaîne de destruction correspondant à son type réel.
    return 0;
}