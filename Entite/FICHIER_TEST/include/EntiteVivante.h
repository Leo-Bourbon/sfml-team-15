#ifndef ENTITEVIVANTE_H
#define ENTITEVIVANTE_H
#include "Entite.h"


class EntiteVivante : public Entite
{
    public:
        EntiteVivante();
        EntiteVivante(Vector2f position, Vector2f taille, RectangleShape forme, std::string nomTexture, Texture &texture, int vieDepart, bool estMort) : Entite(position, taille, forme, nomTexture, texture),
        vie(vieDepart),
        mort(estMort) {}

        virtual ~EntiteVivante();

    protected:
        void subitDegat(int quantite);
        void recoitSoin(int quantite);
        virtual void attaque(EntiteVivante e);

    private:
        int vie;
        bool mort;
};

#endif // ENTITEVIVANTE_H
