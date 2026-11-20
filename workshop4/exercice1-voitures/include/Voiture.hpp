// Empêche cet en-tête d'être inclus plusieurs fois
// pendant la compilation d'un même fichier .cpp.
#pragma once

// Déclare la classe qui représente une voiture classique.
class Voiture {
private:
    // Ces attributs sont accessibles uniquement depuis Voiture.
    int vitesseMax;
    int vitesse;
    int acceleration;

    // Plafonds autorisés pour ce véhicule.
    // Une voiture classique utilise 100 et 3.
    // Une sportive utilise 200 et 8.
    int limiteVitesse;
    int limiteAcceleration;

    // static : une seule variable partagée entre toutes les voitures.
    // inline : permet de l'initialiser directement dans cet en-tête.
    // Ce compteur mémorise le total des objets créés.
    inline static int nombreObjetsCrees{0};

protected:
    // Ce constructeur est accessible à Voiture et à ses classes dérivées.
    // Il permet à VoitureSport de transmettre ses propres plafonds.
    Voiture(
        int vitesseMax,
        int acceleration,
        int limiteVitesse,
        int limiteAcceleration
    );

public:
    // Constructeur appelé quand aucun argument n'est fourni.
    Voiture();

    // Constructeur appelé avec une vitesse maximale et une accélération.
    Voiture(int vitesseMax, int acceleration);

    // Constructeur appelé pour créer une voiture à partir d'une autre.
    // La référence évite de copier le paramètre.
    // const empêche de modifier la voiture reçue via cette référence.
    Voiture(const Voiture& autre);

    // Permet de détruire correctement une VoitureSport
    // lorsqu'elle est gérée par un pointeur de type Voiture.
    // default demande au compilateur de générer le destructeur.
    virtual ~Voiture() = default;

    // Configure les caractéristiques et remet la vitesse à zéro.
    void initialiser(int vitesseMax, int acceleration);

    // virtual permet à VoitureSport de proposer sa propre version.
    virtual void accelerer();

    // Les getters donnent accès aux valeurs des attributs privés.
    // const indique que ces méthodes ne modifient pas l'objet.
    int getVitesseMax() const;
    int getVitesse() const;
    int getAcceleration() const;

    // Renvoie un texte qui identifie le type de voiture.
    // const char* désigne ici une chaîne de caractères fixe.
    // La méthode est virtuelle pour permettre une version sportive.
    virtual const char* getType() const;

    // Une méthode static appartient à la classe.
    // Elle s'appelle avec Voiture::getNombreObjetsCrees().
    static int getNombreObjetsCrees();
};