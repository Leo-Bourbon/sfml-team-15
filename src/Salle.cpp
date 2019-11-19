#include "Salle.h"

Salle::Salle()
{
    portes[0] = NULL;
    portes[1] = NULL;
    portes[2] = NULL;
    portes[3] = NULL;

    finie = false;
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
