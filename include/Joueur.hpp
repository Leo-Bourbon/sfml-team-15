#ifndef JOUEUR_HPP_INCLUDED
#define JOUEUR_HPP_INCLUDED
#include "EntiteVivante.hpp"

class Joueur : public EntiteVivante {
public:
    Joueur();
    Joueur(Vector2f position, Vector2f taille, int vieDepart, bool estMort) : EntiteVivante(position, taille, vieDepart, estMort),
    vecteurProjectile(0,0),
    vitesse(5, 5) {}

    virtual ~Joueur();

    Vector2f getNextPos();
    void deplacer();
    void update(bool moveX, bool moveY);

    void tuer();

    Texture perso1;
    Texture perso2;
    Texture perso3;
    Texture perso4;
    Texture persoMort;

    Vector2f vecteurProjectile;
    Vector2i vitesse;
protected:
private:
};

#endif // JOUEUR_HPP_INCLUDED
