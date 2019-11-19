#ifndef ENTITEVIVANTE_HPP_INCLUDED
#define ENTITEVIVANTE_HPP_INCLUDED

#include "Entite.hpp"


class EntiteVivante : public Entite
{
public:
    EntiteVivante();
    EntiteVivante(Vector2f position, Vector2f taille, int vieDepart, bool estMort) : Entite(position, taille),
        vie(vieDepart),
        mort(estMort),
        degats(0) {}

    virtual ~EntiteVivante();
    virtual void attaque(EntiteVivante e);
    void subitDegat(int quantite);
    void recoitSoin(int quantite);
    int getPV();

    int degats;

protected:
    int vie;
    bool mort;

private:

};

#endif // ENTITEVIVANTE_HPP_INCLUDED
