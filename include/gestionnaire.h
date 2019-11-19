#ifndef GESTIONNAIRE_H
#define GESTIONNAIRE_H
#include "Bouton.h"
#include <SFML/Graphics.hpp>

using namespace sf;
class Gestionnaire
{
public:
    Gestionnaire();
    void CreateBoutton(Vector2f pos, Vector2f taille, Texture& arr, std::string& label);
    void actualiser(RenderWindow &app);
    void AfficherBouttons(sf::Font& Police,sf::RenderWindow& fen);
    virtual ~Gestionnaire();

protected:

private:
    std::vector<Bouton*> liste;
};

#endif // GESTIONNAIRE_H

