#ifndef ENTITE_HPP_INCLUDED
#define ENTITE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

using namespace sf;

class Entite
{
public:
    Entite();
    Entite(Vector2f position, Vector2f taille);
    virtual ~Entite();


    void afficher(RenderWindow &window);
    void setTexture(Texture &texture);
    virtual void deplacer();

    Vector2f getPosition();
    void     setPosition(Vector2f newPosition);
    Vector2f getTaille();
    void     setTaille(Vector2f newTaille);

protected:

    Vector2f position;
    Vector2f taille;
    Vector2f deplacement;
    RectangleShape forme;

private:

};


#endif // ENTITE_HPP_INCLUDED
