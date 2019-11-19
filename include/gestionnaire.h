#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H
#include "Bouton.h"
#include <SFML/Graphics.hpp>


using namespace sf;
class Gestionnaire
{
public:
    Gestionnaire();
    Bouton* CreateBoutton(Vector2f pos, Vector2f taille, Texture& arr, std::string& label);
    void actualiser(RenderWindow &app, Ecran& e);
    void AfficherBouttons(sf::Font& Police,sf::RenderWindow& fen);
    void reset();
    virtual ~Gestionnaire();

protected:

private:
    std::vector<Bouton*> liste;
};

#endif // GESTIONNAIRE_H
