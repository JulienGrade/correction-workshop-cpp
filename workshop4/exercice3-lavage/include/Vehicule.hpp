// Empêche les inclusions répétées de cet en-tête
// pendant la compilation d'un même fichier .cpp.
#pragma once

// Classe commune aux voitures et aux motos.
class Vehicule {
public:
    // Permet de détruire correctement une Voiture ou une Moto
    // lorsqu'elle est gérée par un pointeur Vehicule.
    virtual ~Vehicule() = default;

    // Chaque véhicule doit fournir sa propre méthode de lavage.
    // = 0 rend la méthode virtuelle pure et la classe abstraite.
    // const indique que laver() ne modifie pas les attributs de l'objet.
    virtual void laver() const = 0;
};