#pragma once

class Combattant {
private:
    int pv;
    int pvMax;
    int pa;

protected:
    Combattant(int pv, int pa);
    int tirerDegats() const;
    int soigner(int maximum);
    int getPv() const;
    int getPvMax() const;
    int getPa() const;

public:
    void subitDegat(int degats);
    bool estVivant() const;
    bool restaurerPv(int valeur);
};
