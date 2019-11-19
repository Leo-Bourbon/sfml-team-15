#ifndef JOUEUR_HPP_INCLUDED
#define JOUEUR_HPP_INCLUDED
#include <SFML/Graphics.hpp>
#include "EntiteVivante.hpp"

class Joueur : public EntiteVivante
{
    public:
        Joueur();
        Joueur(Vector2f position, Vector2f taille, int vieDepart, bool estMort) : EntiteVivante(position, taille, vieDepart, estMort){}
        virtual ~Joueur();

        void deplacer();

    protected:

    private:
};

#endif // JOUEUR_HPP_INCLUDED
