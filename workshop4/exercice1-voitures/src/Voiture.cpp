// Rend la déclaration de Voiture accessible dans ce fichier.
#include "Voiture.hpp"

// Fournit std::clamp et std::min.
#include <algorithm>

// Fournit std::cout pour l'affichage dans le Terminal.
#include <iostream>

// Le constructeur sans argument délègue la construction
// au constructeur qui reçoit deux paramètres.
// La voiture utilise donc 100 comme vitesse maximale et 3 comme accélération.
Voiture::Voiture() : Voiture{100, 3} {
}

// Ce constructeur délègue à celui qui reçoit quatre paramètres.
// Les deux derniers arguments fixent les plafonds d'une voiture classique.
Voiture::Voiture(int vitesseMax, int acceleration)
    : Voiture{vitesseMax, acceleration, 100, 3} {
}

// Les constructeurs précédents aboutissent à ce constructeur.
// Une sportive peut aussi l'appeler en transmettant ses propres plafonds.
Voiture::Voiture(
    int vitesseMax,
    int acceleration,
    int limiteVitesse,
    int limiteAcceleration
)
    // La liste d'initialisation initialise les plafonds
    // avant l'exécution du corps du constructeur.
    : limiteVitesse{limiteVitesse},
      limiteAcceleration{limiteAcceleration} {
    // Configure les caractéristiques en respectant ces plafonds.
    initialiser(vitesseMax, acceleration);

    // Ajoute une voiture au total des objets créés.
    // Les constructeurs délégués aboutissent ici :
    // le compteur augmente une seule fois par création.
    ++nombreObjetsCrees;
}

// Une copie doit récupérer l'état complet de la voiture d'origine.
Voiture::Voiture(const Voiture& autre)
    : vitesseMax{autre.vitesseMax},
      vitesse{autre.vitesse},
      acceleration{autre.acceleration},
      limiteVitesse{autre.limiteVitesse},
      limiteAcceleration{autre.limiteAcceleration} {
    // La copie est un nouvel objet : on la compte aussi.
    ++nombreObjetsCrees;
}

void Voiture::initialiser(int vitesseMax, int acceleration) {
    // this->vitesseMax désigne l'attribut de l'objet.
    // vitesseMax désigne le paramètre reçu.
    // clamp maintient la valeur entre 0 et le plafond autorisé.
    this->vitesseMax = std::clamp(vitesseMax, 0, limiteVitesse);

    // Applique la même règle à l'accélération.
    this->acceleration = std::clamp(acceleration, 0, limiteAcceleration);

    // Toute initialisation remet la voiture à l'arrêt.
    vitesse = 0;
}

void Voiture::accelerer() {
    // Une accélération nulle empêcherait la boucle de progresser.
    if (acceleration == 0) {
        std::cout << "Acceleration nulle : la vitesse reste a "
                  << vitesse << " km/h.\n";

        // Quitte immédiatement la méthode.
        return;
    }

    // Répète les instructions tant que le maximum n'est pas atteint.
    while (vitesse < vitesseMax) {
        // Ajoute l'accélération en plafonnant le résultat.
        // Exemple : minimum de 9 + 3 et 10 = 10.
        vitesse = std::min(vitesse + acceleration, vitesseMax);

        // Affiche la nouvelle vitesse après chaque progression.
        std::cout << "Vitesse : " << vitesse << " km/h\n";
    }
}

// Voiture:: indique que la méthode appartient à la classe Voiture.
int Voiture::getVitesseMax() const {
    // Renvoie la valeur au code qui a appelé cette méthode.
    return vitesseMax;
}

int Voiture::getVitesse() const {
    return vitesse;
}

int Voiture::getAcceleration() const {
    return acceleration;
}

const char* Voiture::getType() const {
    // Texte utilisé lorsqu'il s'agit d'une voiture classique.
    return "Voiture";
}

int Voiture::getNombreObjetsCrees() {
    // Renvoie le compteur commun à toutes les voitures.
    return nombreObjetsCrees;
}