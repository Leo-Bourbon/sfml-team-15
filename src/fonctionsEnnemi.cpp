#include "fonctionsEnnemi.hpp"
#include <SFML/Graphics.hpp>
#include "Slime.hpp"

Ennemi* creerEnnemi(Vector2f position, Vector2f taille, Texture &texture, TypeEntite type)
{
    Ennemi *ennemi;
    switch(type)
    {
    case CSouris :
        //ennemi = new CSouris();
        break;
    case S :
        ennemi = new Slime(Vector2f(0,0), Vector2f(100,100), 10, false);
        ennemi->degats = 10;

        break;
    }
    return ennemi;
}



