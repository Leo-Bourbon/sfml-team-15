#include "Entite.h"

Entite::Entite(){
}

Entite::Entite(Vector2f position, Vector2f taille, RectangleShape forme, std::string nomTexture, Texture &texture)
{
    //ctor
    forme.setPosition(position);
    forme.setSize(taille);

    this->nomTexture = nomTexture;

    forme.setTexture(&texture);
}

Entite::~Entite()
{
    //dtor
}

void Entite::afficher(RenderWindow &window)
{
    window.draw(this->forme);
}

void Entite::deplacer()
{

}
