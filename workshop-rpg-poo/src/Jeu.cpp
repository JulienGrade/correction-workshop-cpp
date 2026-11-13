#include "Jeu.hpp"

#include <cstdlib>
#include <iostream>
#include <string>

void Jeu::afficherEtat() const {
    heros.affiche();
    creature.affiche();
}

void Jeu::jouerTour() {
    const int degatsHeros = heros.attaque();
    creature.subitDegat(degatsHeros);
    std::cout << heros.getNom() << " inflige " << degatsHeros << " degats.\n";

    if (creature.estVivant()) {
        const int degatsCreature = creature.attaque();
        heros.subitDegat(degatsCreature);
        std::cout << "La creature inflige " << degatsCreature << " degats.\n";
        ++toursJoues;
    }

    afficherEtat();
}

void Jeu::sauvegarder() const {
    if (sauvegarde.ecrire(heros, creature, toursJoues)) {
        std::cout << "Partie sauvegardee dans " << sauvegarde.getChemin() << ".\n";
    } else {
        std::cout << "Impossible de sauvegarder la partie.\n";
    }
}

void Jeu::charger() {
    if (!sauvegarde.lire(heros, creature, toursJoues)) {
        std::cout << "Sauvegarde absente ou invalide.\n";
        return;
    }

    std::srand(graine);
    for (int i = 0; i < 2 * toursJoues; ++i) {
        std::rand();
    }

    std::cout << "Partie chargee.\n";
    afficherEtat();
}

void Jeu::lancer() {
    std::srand(graine);
    afficherEtat();

    while (heros.estVivant() && creature.estVivant()) {
        std::cout << "\n1. Attaquer\n"
                  << "2. Quitter\n"
                  << "3. Equiper l'epee\n"
                  << "4. Boire la potion\n"
                  << "5. Sauvegarder\n"
                  << "6. Charger\n"
                  << "Ton choix : ";

        std::string choix;
        if (!std::getline(std::cin, choix) || choix == "2") {
            std::cout << "Partie terminee.\n";
            return;
        }

        if (choix == "1") {
            jouerTour();
        } else if (choix == "3") {
            heros.equiperEpee();
            heros.affiche();
        } else if (choix == "4") {
            heros.boirePotion();
            heros.affiche();
        } else if (choix == "5") {
            sauvegarder();
        } else if (choix == "6") {
            charger();
        } else {
            std::cout << "Choix invalide. Saisis un nombre de 1 a 6.\n";
        }
    }

    if (heros.estVivant()) {
        std::cout << "Victoire de " << heros.getNom() << " !\n";
    } else {
        std::cout << heros.getNom() << " est vaincu.\n";
    }
}
