#ifndef SALLE_HPP_INCLUDED
#define SALLE_HPP_INCLUDED

#include "CONSTANTES.hpp"

class Salle
{
public:
    Salle();
    virtual ~Salle();

    TypeEntite carte[HAUTEUR_CASES_SALLE][LARGEUR_CASES_SALLE];

    void setName(char n);
    char getName();

    bool estFinie();

    Salle* portes[4];

protected:
    char name;
    bool finie;
private:
};

#endif // SALLE_HPP_INCLUDED
