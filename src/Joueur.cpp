#include "Joueur.hpp"
#define PAS 1
#include <SFML/Graphics.hpp>

Joueur::Joueur()
{
    //ctor
}

Joueur::~Joueur()
{
    //dtor
}

void Joueur::deplacer() {
    if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        deplacement.y = -PAS;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        deplacement.x = PAS;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        deplacement.y = PAS;
    }
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        deplacement.x = -PAS;
    }
    printf("%i\n", this->deplacement.x);
    this->forme.move(this->deplacement);
    deplacement = Vector2f(0, 0);
}
