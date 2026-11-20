// Empêche les inclusions répétées de cet en-tête
// pendant la compilation d'un même fichier .cpp.
#pragma once

// Classe commune à tous les instruments.
class Instrument {
public:
    // Le destructeur virtuel permet de détruire correctement
    // un Piano ou un Saxophone géré par un pointeur Instrument.
    // default demande au compilateur de générer son implémentation.
    virtual ~Instrument() = default;

    // Chaque instrument doit fournir sa propre manière de jouer.
    // = 0 rend cette méthode virtuelle pure.
    // Instrument devient donc une classe abstraite :
    // on peut manipuler un Instrument par pointeur ou référence,
    // mais on ne peut pas créer directement un objet Instrument.
    // const indique que jouer() ne modifie pas l'instrument.
    virtual void jouer() const = 0;
};