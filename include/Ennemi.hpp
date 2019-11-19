#ifndef ENNEMI_HPP_INCLUDED
#define ENNEMI_HPP_INCLUDED

#include "EntiteVivante.hpp"

class Ennemi : public EntiteVivante
{
public:
    Ennemi();
    Ennemi(Vector2f position, Vector2f taille, int vieDepart, bool estMort) : EntiteVivante(position, taille, vieDepart, estMort) {}
    virtual ~Ennemi();

    Texture slime;

protected:

private:
};

#endif // ENNEMI_HPP_INCLUDED
