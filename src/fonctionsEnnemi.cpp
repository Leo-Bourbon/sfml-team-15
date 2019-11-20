#include <SFML/Graphics.hpp>
#include "fonctionsEnnemi.hpp"
#include "Slime.hpp"
#include "Bat.hpp"

Ennemi* creerEnnemi(Vector2f position, Vector2f taille, Texture &texture, TypeEntite type)
{
    Ennemi *ennemi;
    switch(type)
    {
    case CSouris :
        ennemi = new Bat(position, taille, 20, false);
        ennemi->setTexture(texture);
        ennemi->degats = 5;
        break;
    case Slimy :
        ennemi = new Slime(position, taille, 10, false);
        ennemi->setTexture(texture);
        ennemi->degats = 10;
        break;
    }
    return ennemi;
}



