#pragma once

#include <memory>

// T représente le type des éléments stockés.
template<typename T>
class DynamicArray {
private:
    int count;
    int size;

    // Possède le tableau de valeurs et gère sa destruction.
    std::unique_ptr<T[]> els;

    static constexpr float REFIT_THRESHOLD = 0.8f;
    static constexpr float RESIZE_THRESHOLD = 0.8f;

    // Les méthodes sont maintenant déclarées dans la classe.
    // Leurs définitions se trouvent dans DynamicArray.tpp.
    void resize(int size);
    void fit();

public:
    explicit DynamicArray(int size = 1);

    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

    int add(const T& el);
    bool remove(int i);
    const T* get(int i) const;
    void print() const;
};

// Rend les définitions visibles depuis chaque fichier
// qui inclut DynamicArray.hpp.
// Cette inclusion vient après la définition de la classe.
#include "DynamicArray.tpp"