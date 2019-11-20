#include "Joueur.hpp"
#include <SFML/Graphics.hpp>

Joueur::Joueur() {}
Joueur::~Joueur() {}

void Joueur::deplacer() {
    if(estMort() == false) {
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            this->setTexture(perso4);

            velocite.y = -this->vitesse.y;

            vecteurProjectile.y = -vitesse.y;
            vecteurProjectile.x = 0;
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            this->setTexture(perso3);

            velocite.x = vitesse.x;

            vecteurProjectile.x = vitesse.x;
            vecteurProjectile.y = 0;
        }

        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            this->setTexture(perso1);

            velocite.y = vitesse.y;

            vecteurProjectile.y = vitesse.y;
            vecteurProjectile.x = 0;
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            this->setTexture(perso2);

            velocite.x = -vitesse.x;

            vecteurProjectile.x = -vitesse.x;
            vecteurProjectile.y = 0;
        }
        /*printf("%i\n", vecteurProjectile.x);
        printf("%i\n", -PAS);*/
    }
}

Vector2f Joueur::getNextPos() {
    return this->position + this->velocite;
}

void Joueur::update(bool moveX, bool moveY) {
    this->forme.move(moveX ? this->velocite.x : 0, moveY ? this->velocite.y : 0);
    velocite.x = 0;
    velocite.y = 0;
}

void Joueur::tuer() {
    this->setTexture(persoMort);
}
