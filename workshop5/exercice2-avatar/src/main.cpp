#include "Avatar.hpp"
#include "Emotions.hpp"

int main() {
    // Construit la chaîne en commençant par sa fin.
    // Chaque objet peut ainsi recevoir l'adresse
    // d'un état suivant déjà créé.

    // Dernière émotion : aucun état ne vient après.
    Grumpy grumpy{nullptr};

    // Angry sera suivi de Grumpy.
    Angry angry{&grumpy};

    // Sad sera suivi de Angry.
    Sad sad{&angry};

    // Happy sera suivi de Sad.
    Happy happy{&sad};

    // Glad sera suivi de Happy.
    Glad glad{&happy};

    // L'avatar commence dans l'état Glad.
    Avatar avatar{glad};

    // Affiche les émotions et effectue les transitions.
    avatar.run();

    // Tous les états sont des objets locaux.
    // Ils restent vivants pendant run(), puis sont
    // détruits automatiquement à la fin de main.
    return 0;
}