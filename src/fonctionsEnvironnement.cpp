#include <SFML/Graphics.hpp>
#include "fonctionsEnvironnement.hpp"


Entite* creerEnvironnement(Vector2f position, Vector2f taille, Texture &texture, TypeEntite type)
{
    Entite *e;
    switch(type)
    {
    case Rocher :
        e = new Stone(position, taille);
        e->setTexture(texture);
        break;
    case Trou :
        e = new Hole(position, taille);
        e->setTexture(texture);
        break;
    }
    return e;
}


