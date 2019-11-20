#ifndef FONCTIONSJOUEUR_HPP_INCLUDED
#define FONCTIONSJOUEUR_HPP_INCLUDED

#include "Joueur.hpp"
#include "Fleche.hpp"


Joueur* creerJoueur(Vector2f position, Vector2f taille, Texture &texturePersBas, Texture &texturePersGauche, Texture &texturePersDroite, Texture &texturePersHaut);
Fleche* creerFleche(Vector2f position, Vector2f taille, Texture &fleche);

#endif // FONCTIONSJOUEUR_HPP_INCLUDED
