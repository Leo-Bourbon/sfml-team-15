#ifndef JOUEUR_HPP_INCLUDED
#define JOUEUR_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include "EntiteVivante.hpp"

class Joueur : public EntiteVivante
{
    public:
        Joueur();
        Joueur(Vector2f position, Vector2f taille, std::string nomTexture, Texture &texture, int vieDepart, bool estMort) : EntiteVivante(position, taille, nomTexture, texture, vieDepart, estMort){}
        virtual ~Joueur();

        void deplacer();
    protected:

    private:
        Vector2f position;
};

#endif // JOUEUR_HPP_INCLUDED
