#include "functionsImages.hpp"



void createImage(Vector2f pos, Vector2f taille, Texture& arr,sf::RenderWindow& fen){

    RectangleShape forme(taille);
    forme.setPosition(pos);
    forme.setTexture(&arr);
    fen.draw(forme);
}
