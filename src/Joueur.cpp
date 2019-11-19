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
        this->setTexture(perso4);
        deplacement.y = -PAS;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        this->setTexture(perso3);
        deplacement.x = PAS;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        this->setTexture(perso1);
        deplacement.y = PAS;
    }
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        this->setTexture(perso2);
        deplacement.x = -PAS;
    }
    printf("%i\n", this->deplacement.x);
    this->forme.move(this->deplacement);
    deplacement = Vector2f(0, 0);
}
