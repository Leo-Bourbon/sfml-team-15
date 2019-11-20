#ifndef FUNCTIONSIMAGES_HPP_INCLUDED
#define FUNCTIONSIMAGES_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include "gestionnaire.h"
#include "Bouton.h"
#include "Ennemi.hpp"
#include "Joueur.hpp"
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <string>

using namespace sf;
void afficheTexte(sf::RenderWindow& fen,char mot[ ],sf::Font& Police,Color c,Vector2f pos);
void aficherImage(RectangleShape forme,sf::RenderWindow& fen);
void creeRectangle(Vector2f pos, Vector2f taille,sf::RenderWindow& fen);
void updateVie(Vector2f pos, Vector2f taille, Texture& arr,sf::RenderWindow& fen,Joueur* joueur);
void createurJeu(RectangleShape forme,sf::RenderWindow& fen,Texture& arr);
sf::Text createText(sf::Font& Police, std::string contenu, Color c,Vector2f pos);
sf::Text createText(sf::Font& Police, std::string contenu,Color c,Vector2f pos,int num);
RectangleShape createForme(Vector2f pos, Vector2f taille, Texture& arr);


#endif // FUNCTIONSIMAGES_HPP_INCLUDED
