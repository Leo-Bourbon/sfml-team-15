#include "Joueur.hpp"
#define PAS 2

Joueur::Joueur()
{
    //ctor
}

Joueur::~Joueur()
{
    //dtor
}

void Joueur::deplacer()
{
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        this->deplacement.y -= PAS;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        this->deplacement.x += PAS;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        this->deplacement.y += PAS;
    }
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        this->deplacement.x -= PAS;
    }

    this->forme.move(this->deplacement);
    this->deplacement = Vector2f(0,0);
}
