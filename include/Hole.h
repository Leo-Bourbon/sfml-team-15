#ifndef HOLE_H
#define HOLE_H
#include "Entite.hpp"

class Hole : public Entite
{
    public:
        Hole();
        Hole(Vector2f position, Vector2f taille): Entite(position, taille){};
        virtual ~Hole();

    protected:

    private:
};

#endif // HOLE_H
