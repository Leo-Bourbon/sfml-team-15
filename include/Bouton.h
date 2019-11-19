#ifndef BOUTON_H
#define BOUTON_H
#include <SFML/Graphics.hpp>
#include <string>
#include <sstream>
#include <string.h>
#include <iostream>
using namespace sf;
class Bouton
{
public:
    Bouton();
    Bouton(Vector2f pos, Vector2f tail, Texture& arr);
    Bouton(Vector2f pos, Vector2f taille, Texture& arr, std::string& label);
    void AfficherBouton(sf::Font& Police,sf::RenderWindow& fen);
    bool estAppuye(Vector2f posSouris,std::vector<Bouton*> liste,int i);
    virtual ~Bouton();

protected:

private:
    Vector2f taille;
    Vector2f position;
    Texture arrPlan;
    std::string contenue;
    sf::Text text;
    RectangleShape forme;
    int test;
};

#endif // BOUTON_H
