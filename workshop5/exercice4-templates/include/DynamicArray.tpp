#pragma once

#include <algorithm>
#include <iostream>
#include <utility>

// Chaque définition rappelle qu'elle dépend du paramètre T.
// DynamicArray<T>:: précise la classe à laquelle appartient la méthode.
template<typename T>
DynamicArray<T>::DynamicArray(int size)
    : count{0},
      size{std::max(1, size)},
      els{std::make_unique<T[]>(this->size)} {
}

template<typename T>
void DynamicArray<T>::resize(int size) {
    // Conserve au moins un emplacement et suffisamment de place
    // pour les valeurs déjà présentes.
    const int nouvelleTaille = std::max({1, size, count});

    auto temp = std::make_unique<T[]>(nouvelleTaille);

    for (int i = 0; i < count; ++i) {
        temp[i] = els[i];
    }

    // Transfère la nouvelle allocation et détruit l'ancienne.
    els = std::move(temp);
    this->size = nouvelleTaille;
}

template<typename T>
void DynamicArray<T>::fit() {
    resize(count);
}

template<typename T>
int DynamicArray<T>::add(const T& el) {
    // Préserve la valeur si elle provient du tableau lui-même
    // et qu'un redimensionnement devient nécessaire.
    T copie = el;

    if (count >= RESIZE_THRESHOLD * size) {
        resize(size * 2);
    }

    els[count] = copie;

    // Renvoie l'index utilisé, puis incrémente count.
    return count++;
}

template<typename T>
bool DynamicArray<T>::remove(int i) {
    if (i < 0 || i >= count) {
        return false;
    }

    // Remplace l'élément retiré par le dernier.
    els[i] = els[count - 1];
    --count;

    if (count < REFIT_THRESHOLD * size) {
        fit();
    }

    return true;
}

template<typename T>
const T* DynamicArray<T>::get(int i) const {
    if (i < 0 || i >= count) {
        return nullptr;
    }

    return &els[i];
}

template<typename T>
void DynamicArray<T>::print() const {
    std::cout << "[";

    for (int i = 0; i < count; ++i) {
        if (i > 0) {
            std::cout << ", ";
        }

        std::cout << els[i];
    }

    std::cout << "]";
}