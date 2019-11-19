#include <SFML/Graphics.hpp>
#include "gestionnaire.h"
#include "Bouton.h"



enum Ecran
{
    Principal, Jeu, Fin
};
using namespace sf;
int main()
{
    Ecran e = Principal;
    Font font;
    if (!font.loadFromFile("arial.ttf"))
        return EXIT_FAILURE;

    // Create the main window
    sf::RenderWindow app(sf::VideoMode(1280, 1024), "SFML window");
    Vector2f tailleFenetre(app.getSize());

    // Load a sprite to display


    sf::Texture texture;

    if (!texture.loadFromFile("button.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    std::string debut = "Jouer";
    std::string para = "Paramètres";
    std::string quit = "Quitter";
    std::string instruction = "Instructions";


    Gestionnaire gestionnaire;

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
                sf::Event event;
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



            while (app.isOpen() && e==Jeu)
            {
                // Process events
                sf::Event event;
                while (app.pollEvent(event))
                {
                    // Close window : exit
                    if (event.type == sf::Event::Closed)
                        app.close();
                }

                // Clear screen
                app.clear();

                app.display();
            }
            break;
        case Fin:
            while (app.isOpen())
            {
                // Process events
                sf::Event event;
                while (app.pollEvent(event))
                {
                    // Close window : exit
                    if (event.type == sf::Event::Closed)
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
