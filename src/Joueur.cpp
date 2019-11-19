#include "Joueur.hpp"
#define PAS 1
#include <SFML/Graphics.hpp>

Joueur::Joueur()
{
    //ctor
}

Joueur::~Joueur()
{
    //dtor
}

void Joueur::deplacer() {
    if(estMort() == false) {
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            this->setTexture(perso4);
            deplacement.y = -PAS;
            vecteurProjectile.y = -PAS;
            vecteurProjectile.x = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            this->setTexture(perso3);
            deplacement.x = PAS;
            vecteurProjectile.x = PAS;
            vecteurProjectile.y = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            this->setTexture(perso1);
            deplacement.y = PAS;
            vecteurProjectile.y = PAS;
            vecteurProjectile.x = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            this->setTexture(perso2);
            deplacement.x = -PAS;
            vecteurProjectile.x = -PAS;
            vecteurProjectile.y = 0;
        }
        this->forme.move(this->deplacement);
        deplacement = Vector2f(0, 0);
        printf("%i\n", vecteurProjectile.x);
        printf("%i\n", -PAS);
    }
}

void Joueur::tuer() {
    this->setTexture(persoMort);
}
