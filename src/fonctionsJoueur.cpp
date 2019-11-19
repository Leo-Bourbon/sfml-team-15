#include <SFML/Graphics.hpp>
#include "fonctionsJoueur.hpp"
#include "Joueur.hpp"

Joueur* creerJoueur(Vector2f position, Vector2f taille, Texture &texturePersBas, Texture &texturePersGauche, Texture &texturePersDroite, Texture &texturePersHaut)
{
    Joueur* joueur;
    joueur = new Joueur(position, taille, 100, false);

    joueur->setTexture(texturePersBas);
    joueur->perso1 = texturePersHaut;
    joueur->perso2 = texturePersGauche;
    joueur->perso3 = texturePersDroite;
    joueur->perso4 = texturePersBas;

    return joueur;
}

Fleche* creerFleche(Vector2f position, Vector2f taille, Texture &textureFleche)
{
    Fleche* fleche;
    fleche = new Fleche(position, taille, 1, false);
    fleche->setTexture(textureFleche);

    return fleche;
}
