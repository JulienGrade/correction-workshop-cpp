#pragma once

class Objet {
public:
    virtual ~Objet() = default;

    virtual double aire() const = 0;
    virtual double perimetre() const = 0;
    virtual void afficheInfo() const = 0;
};