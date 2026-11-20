#include "DynamicArray.hpp"

int main() {
    // Crée un tableau dynamique initialement vide.
    DynamicArray arr;

    // Ces trois entiers sont des variables locales.
    int a = 2, b = 3, c = 5;

    // Enregistre leurs adresses aux index 0, 1 et 2.
    arr.add(&a);
    arr.add(&b);
    arr.add(&c);

    // Retire l'adresse de b, située à l'index 1.
    // Le dernier élément, c, prend cet emplacement.
    arr.remove(1);

    // Affiche les deux valeurs restantes.
    arr.print();

    // Le destructeur de arr libérera son tableau de pointeurs.
    return 0;
}