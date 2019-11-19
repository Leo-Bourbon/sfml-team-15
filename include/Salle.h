#ifndef SALLE_H
#define SALLE_H

#include "CONSTANTES.hpp"

class Salle
{
public:
    Salle();
    virtual ~Salle();

    TypeEntite carte[LARGEUR_CASES_SALLE][10];

    void setName(char n);
    char getName();

protected:
    char name;
private:
};

#endif // SALLE_H
