#ifndef ENTITE_H
#define ENTITE_H
#include <SFML/Graphics.hpp>

using namespace sf;

class Entite
{
    public:
        Entite();
        Entite(Vector2f position, Vector2f taille, RectangleShape forme, std::string nomTexture, Texture &texture);
        virtual ~Entite();

    void afficher(RenderWindow &window);
    virtual void deplacer();

    protected:

    private:
    Vector2f position;
    Vector2f taille;
    RectangleShape forme;
    std::string nomTexture;
};

#endif // ENTITE_H
