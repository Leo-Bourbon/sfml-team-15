#ifndef FONCTIONSENNEMI_HPP_INCLUDED
#define FONCTIONSENNEMI_HPP_INCLUDED
#include "Ennemi.hpp"

enum TypeEntite
{
    S, CSouris
};

Ennemi* creerEnnemi(Vector2f position, Vector2f taille, Texture &texture, TypeEntite type);

#endif // FONCTIONSENNEMI_HPP_INCLUDED
