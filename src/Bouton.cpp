#include "Bouton.h"
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
Bouton::Bouton() {}
Bouton::Bouton(Vector2f pos, Vector2f taille, Texture& arr)
{
    this->taille = taille;
    position = pos;
    arrPlan = arr;

    forme = RectangleShape(taille);
    forme.setPosition(pos);
    forme.setTexture(&arr);
}

Bouton::Bouton(Vector2f pos, Vector2f taille, Texture& arr, std::string& label)
{
    this->taille = taille;
    position = pos;
    arrPlan = arr;
    contenue = label;


    forme = RectangleShape(taille);
    forme.setOrigin(taille.x/2,taille.y/2);
    forme.setPosition(pos);
    forme.setTexture(&arr);
    forme.setOutlineThickness(2);
    forme.setOutlineColor(sf::Color::White);


    text.setString(contenue);
    text.setCharacterSize(30);
    text.setColor(Color::White);
    text.setOrigin(text.getLocalBounds().width/2,text.getGlobalBounds().height/2);
    text.setPosition(position.x + taille.x / 2, position.y + taille.y /2);
}
void Bouton::AfficherBouton(sf::Font& Police, sf::RenderWindow& fen)
{
    text.setFont(Police);
    fen.draw(this->forme);
    fen.draw(this->text);
}

bool Bouton::estAppuye(Vector2f posSouris,std::vector<Bouton*> liste,int i)
{


        //std::cout<<liste[i];
        if(liste[i]->forme.getLocalBounds().contains(posSouris))
        {

            //printf("%i",1);
            test = 1;


        }
        else
        {
           // printf("%i",0);
            test = 0;

        }
        return test;



}

Bouton::~Bouton()
{
    //dtor
}

