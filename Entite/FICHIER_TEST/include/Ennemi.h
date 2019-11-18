#ifndef ENNEMI_H
#define ENNEMI_H
#include "EntiteVivante.h"

class Ennemi : public EntiteVivante
{
    public:
        Ennemi();
        Ennemi(Vector2f position, Vector2f taille, RectangleShape forme, std::string nomTexture, Texture &texture, int vieDepart, bool estMort) : EntiteVivante(position, taille, forme, nomTexture, texture, vieDepart, estMort) {}
        virtual ~Ennemi();

    protected:

    private:
};

#endif // ENNEMI_H
