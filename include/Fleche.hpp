#ifndef Fleche_HPP_INCLUDED
#define Fleche_HPP_INCLUDED

#include "EntiteVivante.hpp"

class Fleche : public EntiteVivante
{
    public:
        Fleche();
        Fleche(Vector2f position, Vector2f taille, int vieDepart, bool estMort) : EntiteVivante(position, taille, vieDepart, estMort){}
        virtual ~Fleche();

        void deplacer(Vector2f direction);
        void update();
        Vector2f getNextPos();
    protected:

    private:
};

#endif // Fleche_HPP_INCLUDED
