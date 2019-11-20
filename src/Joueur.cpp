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
            velocite.y = -PAS;
            vecteurProjectile.y = -PAS;
            vecteurProjectile.x = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            this->setTexture(perso3);
            velocite.x = PAS;
            vecteurProjectile.x = PAS;
            vecteurProjectile.y = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            this->setTexture(perso1);
            velocite.y = PAS;
            vecteurProjectile.y = PAS;
            vecteurProjectile.x = 0;
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            this->setTexture(perso2);
            velocite.x = -PAS;
            vecteurProjectile.x = -PAS;
            vecteurProjectile.y = 0;
        }
        this->forme.move(this->velocite);
        velocite = Vector2f(0, 0);
        printf("%i\n", vecteurProjectile.x);
        printf("%i\n", -PAS);
    }
}
