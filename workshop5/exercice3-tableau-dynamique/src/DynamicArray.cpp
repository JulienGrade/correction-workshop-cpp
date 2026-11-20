#include "DynamicArray.hpp"

// Fournit std::max.
#include <algorithm>

// Fournit std::cout.
#include <iostream>

std::string array_element_to_string(ArrayElement* el) {
    // *el donne la valeur de l'entier pointé.
    // to_string transforme cette valeur en chaîne de caractères.
    return std::to_string(*el);
}

DynamicArray::DynamicArray(int size)
    : count{0},
      size{std::max(1, size)},
      els{new ArrayElement*[this->size]} {
    // Le tableau commence vide.
    // On réserve toujours au moins un emplacement.
    // this->size est initialisé avant l'allocation de els.
}

DynamicArray::~DynamicArray() {
    // Libère uniquement le tableau d'adresses.
    // Les entiers pointés appartiennent au code qui les a fournis.
    delete[] els;
}

void DynamicArray::resize(int size) {
    // La nouvelle capacité doit permettre de conserver tous les éléments.
    // Elle doit aussi rester au moins égale à 1.
    const int nouvelleTaille = std::max({1, size, count});

    // Alloue le nouveau tableau avant de modifier l'ancien.
    // Si l'allocation échoue, une exception est propagée
    // et le tableau actuel reste utilisable.
    ArrayElement** temp = new ArrayElement*[nouvelleTaille];

    // Recopie les adresses des éléments existants.
    // Les entiers eux-mêmes restent à leur emplacement d'origine.
    for (int i = 0; i < count; ++i) {
        temp[i] = els[i];
    }

    // Libère l'ancien tableau d'adresses.
    delete[] els;

    // Enregistre le nouveau tableau et sa capacité.
    els = temp;
    this->size = nouvelleTaille;
}

void DynamicArray::fit() {
    // Réduit la capacité au nombre d'éléments.
    // resize() conserve un emplacement si le tableau est vide.
    resize(count);
}

int DynamicArray::add(ArrayElement* el) {
    // Un pointeur vide ne pourrait pas être utilisé par print().
    if (el == nullptr) {
        return -1;
    }

    // Agrandit le tableau lorsque son remplissage atteint le seuil.
    if (count >= RESIZE_THRESHOLD * size) {
        resize(size * 2);
    }

    // Place l'adresse au premier emplacement disponible.
    els[count] = el;

    // Renvoie l'index utilisé, puis augmente le nombre d'éléments.
    return count++;
}

ArrayElement* DynamicArray::remove(int i) {
    // Un index doit être positif ou nul et inférieur à count.
    if (i < 0 || i >= count) {
        return nullptr;
    }

    // Mémorise l'adresse à renvoyer.
    ArrayElement* ptr = els[i];

    // Le tableau contient désormais un élément de moins.
    --count;

    // Remplit l'emplacement libéré avec le dernier élément.
    // Cette stratégie peut modifier l'ordre des éléments.
    els[i] = els[count];

    // Réduit la capacité lorsque le remplissage passe sous le seuil.
    if (count < REFIT_THRESHOLD * size) {
        fit();
    }

    // Rend l'adresse retirée au code appelant.
    return ptr;
}

ArrayElement* DynamicArray::get(int i) {
    // Empêche la lecture d'un emplacement hors du tableau utilisé.
    if (i < 0 || i >= count) {
        return nullptr;
    }

    return els[i];
}

void DynamicArray::print() {
    std::cout << "[";

    // Parcourt uniquement les emplacements contenant un élément.
    for (int i = 0; i < count; ++i) {
        // Ajoute une virgule avant chaque élément sauf le premier.
        if (i > 0) {
            std::cout << ", ";
        }

        // Transforme l'entier pointé en texte, puis l'affiche.
        std::cout << array_element_to_string(els[i]);
    }

    std::cout << "]";
}