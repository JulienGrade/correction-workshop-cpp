#include <cassert>
#include <iostream>

using namespace std;

class Fraction {
private:
    int numerateur;
    int denominateur;

public:
    Fraction()
        : numerateur{1}, denominateur{1} {
    }

    Fraction(int numerateur, int denominateur)
        : numerateur{numerateur}, denominateur{denominateur} {
    }

    int getNumerateur() const {
        return numerateur;
    }

    int getDenominateur() const {
        return denominateur;
    }

    void setNumerateur(int numerateur) {
        this->numerateur = numerateur;
    }

    void setDenominateur(int denominateur) {
        this->denominateur = denominateur;
    }

    Fraction add(const Fraction& autre) const {
        return Fraction{
            numerateur * autre.denominateur + autre.numerateur * denominateur,
            denominateur * autre.denominateur
        };
    }

    Fraction minus(const Fraction& autre) const {
        return Fraction{
            numerateur * autre.denominateur - autre.numerateur * denominateur,
            denominateur * autre.denominateur
        };
    }

    Fraction multiply(const Fraction& autre) const {
        return Fraction{
            numerateur * autre.numerateur,
            denominateur * autre.denominateur
        };
    }

    Fraction divide(const Fraction& autre) const {
        return Fraction{
            numerateur * autre.denominateur,
            denominateur * autre.numerateur
        };
    }

    void simplify() {
        if (denominateur == 0) {
            return;
        }

        long long a = numerateur;
        long long b = denominateur;

        if (a < 0) {
            a = -a;
        }
        if (b < 0) {
            b = -b;
        }

        while (b != 0) {
            const long long reste = a % b;
            a = b;
            b = reste;
        }

        numerateur = static_cast<int>(numerateur / a);
        denominateur = static_cast<int>(denominateur / a);
    }
};

#ifdef TEST_SIMPLIFY

int main() {
    const Fraction f1{1, 2};
    const Fraction f2{3, 4};

    Fraction somme = f1.add(f2);
    assert(somme.getNumerateur() == 10 && somme.getDenominateur() == 8);
    somme.simplify();
    assert(somme.getNumerateur() == 5 && somme.getDenominateur() == 4);
    cout << "[OK] 10/8 devient 5/4\n";

    Fraction difference = f1.minus(f2);
    assert(difference.getNumerateur() == -2 && difference.getDenominateur() == 8);
    difference.simplify();
    assert(difference.getNumerateur() == -1 && difference.getDenominateur() == 4);
    cout << "[OK] -2/8 devient -1/4\n";

    return 0;
}

#else

int main()
{
    /* Test constructors */
    Fraction f0;
    if (f0.getNumerateur() == 1 && f0.getDenominateur() == 1) {
        cout << "[OK] Default constructor works" << endl;
    }
    else {
        cout << "[FAILURE] Default constructor doesn't work" << endl;
    }

    Fraction f1(1, 2);
    if (f1.getNumerateur() == 1 && f1.getDenominateur() == 2) {
        cout << "[OK] Constructor with parameters works" << endl;
    }
    else {
        cout << "[FAILURE] Constructor with parameters doesn't work" << endl;
    }

    Fraction f2(3, 4);

    /* Test add */
    Fraction f3 = f1.add(f2);

    if (f3.getNumerateur() == 10 && f3.getDenominateur() == 8) {
        cout << "[OK] Add method works" << endl;
    }
    else {
        cout << "[FAILURE] Add method doesn't work" << endl;
    }

    /* Test minus */
    f3 = f1.minus(f2);
    if (f3.getNumerateur() == -2 && f3.getDenominateur() == 8) {
        cout << "[OK] Minus method works" << endl;
    }
    else {
        cout << "[FAILURE] Minus method doesn't work" << endl;
    }

    /* Test multiply */
    f3 = f1.multiply(f2);
    if (f3.getNumerateur() == 3 && f3.getDenominateur() == 8) {
        cout << "[OK] Multiply method works" << endl;
    }
    else {
        cout << "[FAILURE] Multiply method doesn't work" << endl;
    }

    /* Test divide */
    f3 = f1.divide(f2);
    if (f3.getNumerateur() == 4 && f3.getDenominateur() == 6) {
        cout << "[OK] Divide method works" << endl;
    }
    else {
        cout << "[FAILURE] Divide method doesn't work" << endl;
    }
    return 0;
}

#endif