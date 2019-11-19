#include "gestionnaire.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Gestionnaire::Gestionnaire()
{
    this->liste.reserve(10);//ctor

}

void Gestionnaire::CreateBoutton(Vector2f pos, Vector2f taille, Texture& arr, std::string& label)
{

    Bouton *b1;
    b1 = new Bouton(pos, taille, arr, label);

    this->liste.push_back(b1);

}
void Gestionnaire::AfficherBouttons(sf::Font& Police,sf::RenderWindow& fen)
{
    for(int i=0; i<liste.size(); i++)
    {
        liste[i]->AfficherBouton(Police,fen);
    }
}

void Gestionnaire::actualiser(RenderWindow &app)
{
    Bouton bouton;
    for(int i=0; i<liste.size(); i++)
    {
        if(bouton.estAppuye(Vector2f(sf::Mouse::getPosition(app).x, sf::Mouse::getPosition(app).y),liste,i))
        {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {



            }
        }

    }



}


Gestionnaire::~Gestionnaire()
{
    //dtor
}
