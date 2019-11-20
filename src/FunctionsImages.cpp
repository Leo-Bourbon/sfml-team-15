#include "functionsImages.hpp"
#include "gestionnaire.h"
#include "Bouton.h"
#include "Ennemi.hpp"
#include "Joueur.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

template <typename T>
std::string to_string(const T& value)
{

    std::stringstream ss;
    ss << value;
    return ss.str();
}

sf::Text createText(sf::Font& Police, std::string contenu,Color c,Vector2f pos)
{
    sf::Text text;
    text.setFont(Police);
    text.setString(contenu);
    text.setCharacterSize(24);
    text.setColor(c);
    text.setPosition(pos);
    return text;
}
sf::Text createText(sf::Font& Police, std::string contenu,Color c,Vector2f pos,int num)
{
    sf::Text text;
    text.setFont(Police);
    text.setString(contenu+to_string(num));
    text.setCharacterSize(24);
    text.setColor(c);
    text.setPosition(pos);
    return text;
}
RectangleShape createForme(Vector2f pos, Vector2f taille, Texture& arr)
{
    RectangleShape forme(taille);
    forme.setPosition(pos);
    forme.setTexture(&arr);
    return forme;
}
void afficheTexte(sf::RenderWindow& fen,char mot[ ],sf::Font& Police,Color c,Vector2f pos)
{
    fen.draw(createText(Police,mot,c,pos));
}

void aficherImage(RectangleShape forme,sf::RenderWindow& fen)
{
    fen.draw(forme);
}
void createurJeu(RectangleShape forme,sf::RenderWindow& fen, Texture& arr)
{
    RectangleShape info=forme;
    if(info.getGlobalBounds().contains(Vector2f(sf::Mouse::getPosition(fen).x, sf::Mouse::getPosition(fen).y)))
    {
        RectangleShape info(sf::Vector2f(400,200));
        info.setTexture(&arr);
        info.setOrigin(0,200);
        info.setPosition(0,forme.getPosition().y+forme.getSize().y);

    fen.draw(info);
    }


}

void updateVie(Vector2f pos, Vector2f taille, Texture& arr,sf::RenderWindow& fen,Joueur* joueur)
{
    sf::Sprite sprite(arr);
    sprite.setPosition(pos);
    sprite.setScale(Vector2f(3.5,3));
    int vie=80;
    int degat=89;

    if(vie<joueur->getPV())
    {

        degat-=10;
        sprite.setTextureRect(sf::IntRect(0, 0,degat, 19));
        vie=vie-10;

    }
    if(vie>joueur->getPV())
    {
        degat+=10;
        sprite.setTextureRect(sf::IntRect(0, 0,degat, 19));
        vie=vie+10;

    }
    if(joueur->getPV()<=0)
    {
        sprite.setTextureRect(sf::IntRect(0, 0,0, 19));
    }
    fen.draw(sprite);

}

void creeRectangle(Vector2f pos, Vector2f taille,sf::RenderWindow& fen)
{
    RectangleShape forme(taille);
    forme.setPosition(pos);
    fen.draw(forme);
}
