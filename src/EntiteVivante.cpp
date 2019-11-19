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
    FloatRect boiteEnglobante = this->forme.getGlobalBounds();
    FloatRect boiteEnglobanteEntite = entite->forme.getGlobalBounds();

    if (boiteEnglobante.intersects(boiteEnglobanteEntite))
    {
        return 1;
    } else {
        return 0;
    }
}
