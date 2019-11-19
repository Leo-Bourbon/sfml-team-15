#include "Entite.hpp"
#include <stdio.h>

Entite::Entite()
{
}

Entite::Entite(Vector2f position, Vector2f taille)
{
    //ctor
    forme = RectangleShape(taille);
    forme.setPosition(position);
}

Entite::~Entite()
{
    //dtor
}

void Entite::afficher(RenderWindow &window)
{
    window.draw(this->forme);
}

void Entite::deplacer()
{

}

void Entite::setTexture(Texture &texture)
{
    this->forme.setTexture(&texture);
}

Vector2f Entite::getPosition()
{
    return this->position;
}

void Entite::setPosition(Vector2f newPosition)
{
    this->position = Vector2f(newPosition);
}

Vector2f Entite::getTaille()
{
    return this->taille;
}

void Entite::setTaille(Vector2f newTaille)
{
    this->taille = Vector2f(newTaille);
}
