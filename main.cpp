#include <SFML/Graphics.hpp>

//Les includes
#include "CONSTANTES.hpp"
#include "gestionnaire.h"
#include "Bouton.h"
#include "Ennemi.hpp"
#include "Joueur.hpp"
#include "fonctionsEnnemi.hpp"
#include "functional"


using namespace sf;
int main()
{
    Ecran e = Principal;

    Font font;
    if (!font.loadFromFile("assets\\arial.ttf"))
        return EXIT_FAILURE;

    // Create the main window
    RenderWindow app(VideoMode(1280, 1024), "The Lone Survivor");
    Vector2f tailleFenetre(app.getSize());
    Vector2f tailleBouton(tailleFenetre.x*0.25,tailleFenetre.y*0.15);

    // Load a sprite to display
    Texture cb;
    if (!cb.loadFromFile("assets\\cb.bmp"))
        return EXIT_FAILURE;

    /* variable interfaces*/
    Texture perso;
    if (!perso.loadFromFile("assets\\perso-1.png"))
        return EXIT_FAILURE;

    Texture texture;
    if (!texture.loadFromFile("assets\\button.png"))
        return EXIT_FAILURE;
    Sprite sprite(texture);
    std::string debut = "Jouer";
    std::string para = "Paramètres";
    std::string quit = "Quitter";
    std::string instruction = "Instructions";
    /* */

    Gestionnaire gestionnaire;

    /* variable Jerem*/
    Ennemi* ennemi;

    /* Variable Mams */
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

                gestionnaire.reset();
                // Clear screen
                app.clear();

                Bouton* b1 = gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/2,tailleFenetre.y*0.20), tailleBouton, texture, debut);
                std::function<void (Ecran&)> myFunction = [](Ecran& e)
                {
                    e = Jeu;
                };
                b1->function = myFunction;


                Bouton* b2 = gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/2,tailleFenetre.y*0.37), tailleBouton, texture, para);
                std::function<void (Ecran&)> myFunction2 = [](Ecran& e)
                {
                    e = Parametre;
                };
                b2->function = myFunction2;
                Bouton* b3 = gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/2,tailleFenetre.y*0.54), tailleBouton, texture, quit);
                std::function<void (Ecran&)> myFunction3 = [](Ecran& e)
                {
                    e = Quitter;
                };
                b3->function = myFunction3;
                Bouton* b4 = gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/2,tailleFenetre.y*0.71), tailleBouton, texture, instruction);
                std::function<void (Ecran&)> myFunction4 = [](Ecran& e)
                {
                    e = Instruction;
                };
                b4->function = myFunction4;



                gestionnaire.AfficherBouttons(font,app);
                gestionnaire.actualiser(app, e);
                app.display();

            }
            break;
        case Jeu:
            //Code au demarrage de l'ecran de jeu
            ennemi = creerEnnemi(Vector2f(50,50), Vector2f(50,50), cb, Slimy);
            joueur = new Joueur(Vector2f(500, 500), Vector2f(200, 200), 100, false);
            if (!joueur->perso1.loadFromFile("assets\\perso-1.png"))
                return EXIT_FAILURE;

            if (!joueur->perso2.loadFromFile("assets\\perso-2.png"))
                return EXIT_FAILURE;

            if (!joueur->perso3.loadFromFile("assets\\perso-3.png"))
                return EXIT_FAILURE;

            if (!joueur->perso4.loadFromFile("assets\\perso-4.png"))
                return EXIT_FAILURE;

            joueur->setTexture(perso);

            while (app.isOpen() && e==Jeu)
            {
                joueur->deplacer();
                if (joueur->collision(ennemi) == 1) {
                    joueur->subitDegat(ennemi->degats);
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

                ennemi->afficher(app);
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
        case Instruction:



            while (app.isOpen() && e == Instruction)
            {
                // Process events
                sf::Event event;
                while (app.pollEvent(event))
                {
                    // Close window : exit
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
                gestionnaire.reset();

                // Clear screen
                app.clear();

                Bouton* b3 = gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/2,tailleFenetre.y*0.54), tailleBouton, texture, quit);
                std::function<void (Ecran&)> myFunction3 = [](Ecran& e)
                {
                    e = Principal;
                };
                b3->function = myFunction3;
                gestionnaire.AfficherBouttons(font,app);
                gestionnaire.actualiser(app, e);
                app.display();
            }
            break;
        case Quitter:
            app.close();
            break;
        }
    }
    return EXIT_SUCCESS;
}
