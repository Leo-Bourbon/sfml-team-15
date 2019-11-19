#include <SFML/Graphics.hpp>

//Les includes
#include "CONSTANTES.hpp"
#include "gestionnaire.h"
#include "Bouton.h"
#include "Ennemi.hpp"
#include "Joueur.hpp"
#include "fonctionsEnnemi.hpp"
#include "functional"
#include "functionsImages.hpp"



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

    Texture perso;
    if (!perso.loadFromFile("assets\\perso-1.png"))
        return EXIT_FAILURE;
    /* variable interfaces*/


    Texture texture;

    if (!texture.loadFromFile("assets\\button.png"))
        return EXIT_FAILURE;

    Texture logo;

    if (!logo.loadFromFile("assets\\LogoJeu.png"))
        return EXIT_FAILURE;
    Texture background;

    if (!background.loadFromFile("assets\\background.png"))
        return EXIT_FAILURE;

    std::string debut = "Jouer";
    std::string para = "Paramètres";
    std::string quit = "Quitter";
    std::string instruction = "Instructions";
    /* */

    Gestionnaire gestionnaire;
    Bouton* b1;
    Bouton* b2;
    Bouton* b3;
    Bouton* b4;
    Bouton* b5;
    Bouton* b6;
    Bouton* b7;

    std::function<void (Ecran&)> myFunction = [](Ecran& e)
    {
        e = Jeu;
    };
    std::function<void (Ecran&)> myFunction2 = [](Ecran& e)
    {
        e = Parametre;
    };
    std::function<void (Ecran&)> myFunction3 = [](Ecran& e)
    {
        e = Instruction;
    };
    std::function<void (Ecran&)> myFunction4 = [](Ecran& e)
    {
        e = Quitter;
    };
    std::function<void (Ecran&)> myFunction5 = [](Ecran& e)
    {
        e = Principal;
    };

    // variable Jerem
    Ennemi* ennemi;

    // variables Mams
    Joueur* joueur;

    /*Textures personnage joueur*/
    Texture texturePersBas;
    Texture texturePersDroite;
    Texture texturePersGauche;
    Texture texturePersHaut;

    if (!texturePersBas.loadFromFile("assets\\perso-4.png"))
        return EXIT_FAILURE;
    if (!texturePersHaut.loadFromFile("assets\\perso-1.png"))
        return EXIT_FAILURE;
    if (!texturePersGauche.loadFromFile("assets\\perso-2.png"))
        return EXIT_FAILURE;
    if (!texturePersDroite.loadFromFile("assets\\perso-3.png"))
        return EXIT_FAILURE;
    /*                         */

    // Start the game loop
    while(1)
    {
        // Start the game loop
        switch(e)
        {
        case Principal:
            gestionnaire.reset();
            b1  = gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/1.25,tailleFenetre.y*0.35), tailleBouton, texture, debut);
            b1->function = myFunction;
            b2 = gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/1.25,tailleFenetre.y*0.52), tailleBouton, texture, para);
            b2->function = myFunction2;
            b3 = gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/1.25,tailleFenetre.y*0.69), tailleBouton, texture, instruction);
            b3->function = myFunction3;
            b4 = gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/1.25,tailleFenetre.y*0.86), tailleBouton, texture, quit);
            b4->function = myFunction4;
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
                // Clear screen
                app.clear();

                createImage(Vector2f(0,0),Vector2f(tailleFenetre), background,app);
                createImage(Vector2f(-10,-50), Vector2f(1000,500), logo,app);
                gestionnaire.AfficherBouttons(font,app);
                gestionnaire.actualiser(app, e);
                app.display();

            }
            break;
        case Jeu:
            //Code au demarrage de l'ecran de jeu
            ennemi = creerEnnemi(Vector2f(50,50), Vector2f(50,50), cb, Slimy);

            joueur = new Joueur(Vector2f(500, 500), Vector2f(200, 200), 100, false);
            joueur->perso1 = texturePersHaut;
            joueur->perso2 = texturePersGauche;
            joueur->perso3 = texturePersDroite;
            joueur->perso4 = texturePersBas;


            joueur->setTexture(perso);

            while (app.isOpen() && e==Jeu)
            {
                joueur->deplacer();
                if (joueur->collision(ennemi) == 1)
                {
                    joueur->subitDegat(ennemi->degats);
                    printf("Vie : %i\n", joueur->vie);
                    printf("Mort : %i\n", joueur->estMort());
                }

                // Process events
                Event event;
                while (app.pollEvent(event))
                {
                    // Close window : exit
                    switch(event.type)
                    {
                    // Close window : exit
                    case Event::Closed :
                        app.close();
                        break;
                    case Event::KeyPressed:
                        if(event.key.code==Keyboard::Escape)
                            e = Principal;
                        break;
                    default:
                        break;
                    }
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
            gestionnaire.reset();
            b3 = gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/2,tailleFenetre.y*0.85), tailleBouton, texture, quit);

            b3->function = myFunction5;


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


                // Clear screen
                app.clear();

                createImage(Vector2f(0,0),Vector2f(tailleFenetre), background,app);
                gestionnaire.AfficherBouttons(font,app);
                gestionnaire.actualiser(app, e);
                app.display();
            }
            break;
        case Parametre:

            gestionnaire.reset();
            b7 = gestionnaire.CreateBoutton(Vector2f(tailleFenetre.x/2,tailleFenetre.y*0.85), tailleBouton, texture, quit);
            b7->function = myFunction5;
            while (app.isOpen() && e == Parametre)
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


                // Clear screen
                app.clear();
                createImage(Vector2f(0,0),Vector2f(tailleFenetre), background,app);
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
