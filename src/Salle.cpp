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

Salle::~Salle()
{
    //dtor
}


void Salle::setName(char n)
{
    this->name = n;
}

char Salle::getName()
{
    return this->name;
}

bool Salle::estFinie()
{
    return this->finie;
};

void Salle::setFinie(bool finie)
{
    this->finie = finie;
};
