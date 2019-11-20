#include "Salle.hpp"

Salle::Salle()
{
    portes[0] = NULL;
    portes[1] = NULL;
    portes[2] = NULL;
    portes[3] = NULL;

    finie = false;
    styleArrPlan = 0;
}

void Salle::setName(char n)
{
    this->name = n;
}

char Salle::getName()
{
    return this->name;
}

Salle::~Salle()
{
    //dtor
}
