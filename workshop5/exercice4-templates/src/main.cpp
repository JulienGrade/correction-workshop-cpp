#include "DynamicArray.hpp"

#include <iostream>
#include <string>

int main() {
    // Le compilateur utilise la classe avec T = int.
    DynamicArray<int> nombres;

    // On fournit maintenant les valeurs directement.
    nombres.add(2);
    nombres.add(3);
    nombres.add(5);

    // Retire 3. Le dernier élément, 5, prend sa place.
    nombres.remove(1);

    std::cout << "Entiers : ";
    nombres.print();
    std::cout << '\n';

    // Le même code de classe fonctionne avec T = std::string.
    DynamicArray<std::string> mots;

    // Les textes sont convertis en std::string puis copiés.
    mots.add("Hello");
    mots.add("C++");
    mots.add("World");

    mots.remove(1);

    std::cout << "Textes : ";
    mots.print();
    std::cout << '\n';

    // get() renvoie ici un pointeur vers une std::string.
    const std::string* premier = mots.get(0);

    if (premier != nullptr) {
        std::cout << "Premier texte : " << *premier << '\n';
    }

    return 0;
}