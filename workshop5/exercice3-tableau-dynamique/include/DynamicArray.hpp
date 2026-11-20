#pragma once

#include <string>

// Crée un autre nom pour le type int.
// Pour cet exercice, chaque élément du tableau est donc un entier.
typedef int ArrayElement;

// Déclare la fonction qui transforme un élément en texte.
std::string array_element_to_string(ArrayElement* el);

// Définit la structure de la classe.
// Les corps des méthodes seront écrits dans DynamicArray.cpp.
class DynamicArray {
private:
    // Nombre d'éléments actuellement enregistrés.
    int count;

    // Nombre d'emplacements actuellement alloués.
    int size;

    // Adresse d'un tableau de pointeurs vers les éléments.
    // Le tableau conserve les adresses des entiers fournis par main.
    ArrayElement** els;

    // Seuils de remplissage qui déclenchent les redimensionnements.
    // Ces constantes sont communes à toutes les instances.
    static constexpr float REFIT_THRESHOLD = 0.8f;
    static constexpr float RESIZE_THRESHOLD = 0.8f;

    // Modifie le nombre d'emplacements disponibles.
    void resize(int size);

    // Ajuste la capacité au nombre d'éléments.
    void fit();

public:
    // Réserve un emplacement par défaut.
    explicit DynamicArray(int size = 1);

    // Libère le tableau de pointeurs à la destruction de l'objet.
    ~DynamicArray();

    // Une copie automatique partagerait le même tableau de pointeurs.
    // Les deux objets tenteraient ensuite de libérer la même allocation.
    // On interdit ici la copie pour éviter cette situation.
    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;

    // Ajoute une adresse et renvoie son index.
    // Renvoie -1 si le pointeur est vide.
    int add(ArrayElement* el);

    // Retire un élément et renvoie son adresse.
    // Renvoie nullptr si l'index est invalide.
    ArrayElement* remove(int i);

    // Renvoie l'adresse de l'élément situé à cet index.
    // Renvoie nullptr si l'index est invalide.
    ArrayElement* get(int i);

    // Affiche les valeurs présentes dans le tableau.
    void print();
};