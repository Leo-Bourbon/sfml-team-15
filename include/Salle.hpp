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
    void setFinie(bool finie);

    Salle* portes[4];
    int styleArrPlan;

protected:
    char name;
    bool finie;
private:
};

#endif // SALLE_HPP_INCLUDED
