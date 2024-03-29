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
    this->vie-=quantite;

    if(this->vie<=0)
        mort=true;
}

void EntiteVivante::recoitSoin(int quantite)
{
    this->vie+=quantite;
}

void EntiteVivante::attaque(EntiteVivante cible, int degats)
{
    cible.subitDegat(degats);
}

int EntiteVivante::getPV()
{
    return this->vie;
}

int EntiteVivante::collision(Entite* entite)
{

    FloatRect boiteEntite1 = this->forme.getGlobalBounds();
    FloatRect boiteEntite2 = entite->forme.getGlobalBounds();

    if(boiteEntite1.intersects(boiteEntite2))
        return 1;
    else return 0;
}

bool EntiteVivante::estMort()
{
    if(this->getPV() <= 0)
        return true;
    else return false;
}
