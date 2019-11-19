#ifndef FUNCTIONSIMAGES_HPP_INCLUDED
#define FUNCTIONSIMAGES_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include "gestionnaire.h"
#include "Bouton.h"
#include "Ennemi.hpp"
#include "Joueur.hpp"

using namespace sf;

void createImage(Vector2f pos, Vector2f taille, Texture& arr,sf::RenderWindow& fen);
void creeRectangle(Vector2f pos, Vector2f taille,sf::RenderWindow& fen);
void updateVie(Vector2f pos, Vector2f taille, Texture& arr,sf::RenderWindow& fen,Joueur* joueur);

#endif // FUNCTIONSIMAGES_HPP_INCLUDED
