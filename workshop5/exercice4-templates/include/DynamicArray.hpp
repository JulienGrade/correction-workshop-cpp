#pragma once

#include <algorithm>
#include <iostream>
#include <memory>
#include <utility>

// T est un paramètre représentant le type des éléments.
// DynamicArray<int> utilise int à la place de T.
// DynamicArray<std::string> utilise std::string à la place de T.
template<typename T>
class DynamicArray {
private:
    // Nombre d'éléments utilisés et capacité disponible.
    int count;
    int size;

    // Tableau qui contient directement des valeurs de type T.
    // unique_ptr libère automatiquement l'allocation avec delete[].
    std::unique_ptr<T[]> els;

    static constexpr float REFIT_THRESHOLD = 0.8f;
    static constexpr float RESIZE_THRESHOLD = 0.8f;

    void resize(int size) {
        // Conserve suffisamment de place pour les éléments existants.
        const int nouvelleTaille = std::max({1, size, count});

        // Alloue un nouveau tableau de valeurs de type T.
        auto temp = std::make_unique<T[]>(nouvelleTaille);

        // Copie les valeurs existantes dans ce nouveau tableau.
        for (int i = 0; i < count; ++i) {
            temp[i] = els[i];
        }

        // Transfère la nouvelle allocation à els.
        // L'ancien tableau est automatiquement détruit.
        els = std::move(temp);
        this->size = nouvelleTaille;
    }

    void fit() {
        resize(count);
    }

public:
    explicit DynamicArray(int size = 1)
        : count{0},
          size{std::max(1, size)},
          els{std::make_unique<T[]>(this->size)} {
    }

    // On conserve l'interdiction de copier le tableau.
    // Une copie indépendante demanderait sa propre implémentation.
    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

    int add(const T& el) {
        // Conserve la valeur avant un éventuel redimensionnement.
        // Cela permet aussi d'ajouter une valeur déjà stockée
        // dans le tableau sans perdre sa référence pendant resize().
        T copie = el;

        if (count >= RESIZE_THRESHOLD * size) {
            resize(size * 2);
        }

        // Stocke une copie de la valeur dans le tableau.
        els[count] = copie;

        // Renvoie l'index utilisé, puis augmente le compteur.
        return count++;
    }

    bool remove(int i) {
        if (i < 0 || i >= count) {
            return false;
        }

        // Remplace la valeur retirée par la dernière valeur.
        // Comme dans l'exercice 3, l'ordre peut donc changer.
        els[i] = els[count - 1];
        --count;

        if (count < REFIT_THRESHOLD * size) {
            fit();
        }

        return true;
    }

    const T* get(int i) const {
        if (i < 0 || i >= count) {
            return nullptr;
        }

        // Donne un accès en lecture à la valeur stockée.
        return &els[i];
    }

    void print() const {
        std::cout << "[";

        for (int i = 0; i < count; ++i) {
            if (i > 0) {
                std::cout << ", ";
            }

            // Utilise l'opérateur d'affichage du type T.
            // Il existe déjà pour int et std::string.
            std::cout << els[i];
        }

        std::cout << "]";
    }
};