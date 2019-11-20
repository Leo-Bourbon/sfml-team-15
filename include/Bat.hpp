#ifndef BAT_HPP_INCLUDED
#define BAT_HPP_INCLUDED
#include "Ennemi.hpp"

class Bat : public Ennemi
{
    public:
        Bat();
        Bat(Vector2f position, Vector2f taille, int vieDepart, bool estMort) : Ennemi(position, taille, vieDepart, estMort){}
        virtual ~Bat();

    protected:

    private:
};

#endif // BAT_HPP_INCLUDED
