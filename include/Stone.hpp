#ifndef STONE_HPP_INCLUDED
#define STONE_HPP_INCLUDED
#include "Entite.hpp"

class Stone : public Entite
{
    public:
        Stone();
        Stone(Vector2f position, Vector2f taille): Entite(position, taille){};
        virtual ~Stone();

    protected:

    private:
};

#endif // STONE_HPP_INCLUDED
