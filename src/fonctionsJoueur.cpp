#include <SFML/Graphics.hpp>
#include "fonctionsJoueur.hpp"
#include "Joueur.hpp"

Joueur* creerJoueur(Vector2f position, Vector2f taille, Texture &texturePersBas, Texture &texturePersGauche, Texture &texturePersDroite, Texture &texturePersHaut)
{
    Joueur* joueur;
    joueur = new Joueur(Vector2f(500, 500), Vector2f(200, 200), 100, false);

    joueur->setTexture(texturePersBas);
    joueur->perso1 = texturePersHaut;
    joueur->perso2 = texturePersGauche;
    joueur->perso3 = texturePersDroite;
    joueur->perso4 = texturePersBas;
    joueur->setTexture(texturePersHaut);

    return joueur;
}
