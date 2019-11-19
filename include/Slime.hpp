#ifndef SLIME_HPP_INCLUDED
#define SLIME_HPP_INCLUDED
#include "Ennemi.hpp"

class Slime : public Ennemi
{
public:
    Slime();
    Slime(Vector2f position, Vector2f taille, int vieDepart, bool estMort) : Ennemi(position, taille, vieDepart, estMort){}
    virtual ~Slime();

protected:

private:
};

#endif // SLIME_HPP_INCLUDED
