#ifndef JOUEUR_H
#define JOUEUR_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Joueur
{
    public:
        Joueur();
        virtual ~Joueur();

    protected:

    private:
        Vector2f position;
};

#endif // JOUEUR_H
