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
    int vie;

    virtual ~EntiteVivante();
    virtual void attaque(EntiteVivante cible, int degats);
    void subitDegat(int quantite);
    void recoitSoin(int quantite);
    int getPV();
    int collision(Entite *entite);

    int degats;

protected:
    bool mort;

private:

};

#endif // ENTITEVIVANTE_HPP_INCLUDED
