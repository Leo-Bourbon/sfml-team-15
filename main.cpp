#include <SFML/Graphics.hpp>

//Les includes
#include "CONSTANTES.hpp"
#include "gestionnaire.h"
#include "Bouton.h"
#include "Ennemi.hpp"
#include "EntiteVivante.hpp"
#include "Joueur.hpp"
#include "fonctionsEnnemi.hpp"

using namespace sf;
int main()
{
    Ecran e = Principal;

    Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;

    // Create the main window
    RenderWindow app(VideoMode(1280, 1024), "SFML window");
    Vector2f tailleFenetre(app.getSize());

    // Load a sprite to display

    Texture cb;
    if (!cb.loadFromFile("cb.bmp"))
        return EXIT_FAILURE;

    Texture perso;
    if (!perso.loadFromFile("perso.png"))
        return EXIT_FAILURE;

    Texture texture;
    if (!texture.loadFromFile("button.png"))
        return EXIT_FAILURE;
    Sprite sprite(texture);
    std::string debut = "Jouer";
    std::string para = "Paramètres";
    std::string quit = "Quitter";
    std::string instruction = "Instructions";


    Gestionnaire gestionnaire;

     Ennemi* ennemi2;
     Joueur* joueur;

    // Start the game loop
    while(1)
    {
        // Start the game loop
        switch(e)
        {
        case Principal:
            while (app.isOpen() && e == Principal)
            {
                // Process events
                Event event;
                while (app.pollEvent(event))
                {
                    switch(event.type)
                    {
                    // Close window : exit
                    case Event::Closed :
                        app.close();
                        break;
                    default:
                        break;
                    }
                }

                if(Keyboard::isKeyPressed(Keyboard::Return)) e = Jeu;

                // Clear screen
                app.clear();

                gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/2,tailleFenetre.y*0.20), Vector2f(tailleFenetre.x*0.25,tailleFenetre.y*0.25), texture, debut);
                gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/2,tailleFenetre.y*0.40), Vector2f(tailleFenetre.x*0.25,tailleFenetre.y*0.25), texture, para);
                gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/2,tailleFenetre.y*0.60), Vector2f(tailleFenetre.x*0.25,tailleFenetre.y*0.25), texture, quit);
                gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/2,tailleFenetre.y*0.80), Vector2f(tailleFenetre.x*0.25,tailleFenetre.y*0.25), texture, instruction);

                gestionnaire.AfficherBouttons(font,app);
                gestionnaire.actualiser(app);
                app.display();

            }
            break;
        case Jeu:
            //Code au demarrage de l'ecran de jeu

            ennemi2 = creerEnnemi(Vector2f(50,50), Vector2f(50,50), cb, S);
            joueur = new Joueur(Vector2f(500, 500), Vector2f(200, 200), 100, false);
            joueur->setTexture(perso);

            while (app.isOpen() && e==Jeu)
            {
                joueur->deplacer();
                if (joueur->collision(ennemi2) == 1) {
                    joueur->subitDegat(ennemi2->degats);
                }

                printf("%i", joueur->vie);

                // Process events
                Event event;
                while (app.pollEvent(event))
                {
                    // Close window : exit
                    if (event.type == Event::Closed)
                        app.close();
                }

                // Clear screen
                app.clear();

                ennemi2->afficher(app);
                joueur->afficher(app);

                app.display();
            }
            break;

        case Fin:
            while (app.isOpen())
            {
                // Process events
                Event event;
                while (app.pollEvent(event))
                {
                    // Close window : exit
                    if (event.type == Event::Closed)
                        app.close();
                }

                // Clear screen
                app.clear();
                app.display();
            }
            break;
        }
    }
    return EXIT_SUCCESS;
}
