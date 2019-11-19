#include "EntiteVivante.hpp"

EntiteVivante::EntiteVivante()
{
}

EntiteVivante::~EntiteVivante()
{
    //dtor
}

void EntiteVivante::subitDegat(int quantite)
{
    vie -= quantite;

    if(vie<=0)
        mort=true;
}

void EntiteVivante::recoitSoin(int quantite)
{
    vie+=quantite;
}

void EntiteVivante::attaque(EntiteVivante e)
{

}

int EntiteVivante::getPV()
{
    return this->vie;
}
