#include <iostream>
#include <type_traits>

class Objet {
public:
    virtual ~Objet() = default;

    virtual double aire() const = 0;
    virtual double perimetre() const = 0;
    virtual void afficheInfo() const = 0;
};

class Rectangle : public Objet {
private:
    double largeur;
    double longueur;

public:
    Rectangle(double l, double lg) : largeur{l}, longueur{lg} {
    }

    double getLargeur() const {
        return largeur;
    }

    double getLongueur() const {
        return longueur;
    }

    double aire() const override {
        return largeur * longueur;
    }

    double perimetre() const override {
        return 2 * (largeur + longueur);
    }

    void afficheInfo() const override {
        std::cout << "Rectangle de largeur " << largeur
                  << " et de longueur " << longueur << '\n';
    }
};

class Carre : public Objet {
private:
    double cote;

public:
    explicit Carre(double c) : cote{c} {
    }

    double getCote() const {
        return cote;
    }

    double aire() const override {
        return cote * cote;
    }

    double perimetre() const override {
        return 4 * cote;
    }

    void afficheInfo() const override {
        std::cout << "Carre de cote " << cote << '\n';
    }
};

int main() {
    static_assert(std::is_abstract_v<Objet>);
    static_assert(!std::is_abstract_v<Rectangle>);
    static_assert(!std::is_abstract_v<Carre>);

    std::cout << "La hierarchie des formes est valide.\n";

    return 0;
}