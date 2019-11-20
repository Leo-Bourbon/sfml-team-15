#include "functionsImages.hpp"
#include "gestionnaire.h"
#include "Bouton.h"
#include "Ennemi.hpp"
#include "Joueur.hpp"


void createImage(Vector2f pos, Vector2f taille, Texture& arr,sf::RenderWindow& fen)
{
    RectangleShape forme(taille);
    forme.setPosition(pos);
    forme.setTexture(&arr);
    fen.draw(forme);
}

void updateVie(Vector2f pos, Vector2f taille, Texture& arr,sf::RenderWindow& fen,Joueur* joueur)
{
    createImage(pos,taille,arr,fen) ;
}

void creeRectangle(Vector2f pos, Vector2f taille,sf::RenderWindow& fen){
    RectangleShape forme(taille);
    forme.setPosition(pos);
    fen.draw(forme);
}
