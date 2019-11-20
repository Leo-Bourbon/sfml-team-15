#include "Etage.h"

Etage::Etage(std::vector<Salle> listeSalles, RenderWindow* app, std::map<TypeEntite, Texture*>& listeTex)
{
    this->listeSalles = listeSalles;
    this->listeTextures = listeTex;

    this->frametime = 1.0f / 60.0f;
    this->fen = app;

    this->arrPlan = RectangleShape(Vector2f(app->getSize().x * LARGEUR_SALLES, app->getSize().y * HAUTEUR_SALLES));
    this->arrPlan.setPosition(Vector2f((app->getSize().x - arrPlan.getGlobalBounds().width) / 2, (app->getSize().y - arrPlan.getGlobalBounds().height) / 2));
    this->arrPlan.setOutlineThickness(1);
    this->arrPlan.setOutlineColor(sf::Color::White);

    salleActuelle = 0;
}

Etage::~Etage()
{
    //dtor
}

void Etage::setJoueur(Joueur* j)
{
    this->joueur = j;

    genererEtage();
}

void Etage::setTexture(Texture& tex)
{
    this->arrPlan.setTexture(&tex);
}

void Etage::handleInput()
{
    this->joueur->deplacer();
};

void Etage::genererEtage()
{
    salles[0] = listeSalles[0];

    for(int index = 0; index < 4; index++)
    {
        for(int j = 0; j < HAUTEUR_CASES_SALLE; j++)
        {
            for(int i = 0; i < LARGEUR_CASES_SALLE; i++)
            {
                Entite* e;

                float x = arrPlan.getPosition().x + ((i * this->arrPlan.getSize().x) / LARGEUR_CASES_SALLE);
                float y = arrPlan.getPosition().y + this->joueur->getTaille().y + ((j * arrPlan.getSize().y) / HAUTEUR_CASES_SALLE);

                //printf("%i\n", salles[0].carte[j][i]);
                switch(salles[index].carte[j][i])
                {
                case Sol:
                    break;
                case Personnage:
                    printf("i=%i j=%i\n", i, j);
                    this->joueur->setPosition(Vector2f(x, y));
                    break;
                case Rocher:
                    break;
                case Trou:
                    break;
                case CSouris:
                    break;
                case Slimy:
                    e = creerEnnemi(Vector2f(0,0), Vector2f(56, 42), *listeTextures[Slimy], Slimy);
                    ajouterEntite(e);
                    e->setPosition(Vector2f(x, y));
                    break;
                case Item:
                    break;
                default:
                    break;
                }
            }
        }
    }
};

Salle generer

void Etage::ajouterEntite(Entite* e)
{
    this->listeEntites.push_back(e);
}

void Etage::afficherSalle(sf::RenderWindow& app)
{
    app.draw(this->arrPlan);
};

void Etage::afficherEntites(sf::RenderWindow& app)
{
    for(int i = 0; i < this->listeEntites.size(); i++)
    {
        listeEntites[i]->afficher(app);
    }
};

void Etage::afficher()
{
    afficherSalle((*fen));
    afficherEntites((*fen));
    joueur->afficher((*fen));
};

bool Etage::checkCollisionsX(Joueur* e)
{
    sf::FloatRect curPos(e->forme.getGlobalBounds());
    //printf("Current pos : %f %f %f %f\n", curPos.left, curPos.top, curPos.width, curPos.height);

    sf::FloatRect nextPos(curPos.left + e->velocite.x, curPos.top, curPos.width, curPos.height);
    //printf("Next pos : %f %f %f %f\n", nextPos.left, nextPos.top, nextPos.width, nextPos.height);

    if(nextPos.left < ((fen->getSize().x * 1/4)/2) + (arrPlan.getGlobalBounds().width * 1/9 ) || nextPos.left + nextPos.width > (fen->getSize().x * 7/8) - (arrPlan.getGlobalBounds().width * 1/9 ))
        return false;

    for(int i = 0; i < this->listeEntites.size(); i++)
    {
        if(listeEntites[i] == e)
            continue;

        if(nextPos.intersects(listeEntites[i]->forme.getGlobalBounds()))
        {
            return false;
        }
    }
    return true;
}

bool Etage::checkCollisionsY(Joueur* j)
{
    sf::FloatRect curPos(j->forme.getGlobalBounds());
    //printf("Current pos : %f %f %f %f\n", curPos.left, curPos.top, curPos.width, curPos.height);

    sf::FloatRect nextPos(curPos.left, curPos.top + j->velocite.y, curPos.width, curPos.height);
    //printf("Next pos : %f %f %f %f\n", nextPos.left, nextPos.top, nextPos.width, nextPos.height);

    if(nextPos.top < ((fen->getSize().y * 1/6)/2) + (arrPlan.getGlobalBounds().height * 1/6 ) || nextPos.top + nextPos.height > (fen->getSize().y * 5/6) - (arrPlan.getGlobalBounds().height * 1/6 ))
        return false;

    for(int i = 0; i < this->listeEntites.size(); i++)
    {
        if(listeEntites[i] == j)
            continue;

        if(nextPos.intersects(listeEntites[i]->forme.getGlobalBounds()))
        {
            return false;
        }
    }
    return true;
}

void Etage::checkCollisionsDmg(Joueur* j)
{
    sf::FloatRect curPos(j->forme.getGlobalBounds());
    sf::FloatRect hitBox(curPos.left - 10, curPos.top - 10, curPos.width + 10, curPos.height + 10);

    for(int i = 0; i < this->listeEntites.size(); i++)
    {
        if(listeEntites[i] == j)
            continue;

        printf("%s", typeid(*listeEntites[i]).name());

        if(dynamic_cast<Ennemi*>(listeEntites[i]))
        {
            printf("Cast\n");
            sf::FloatRect otherPos(listeEntites[i]->forme.getGlobalBounds());

            if (curPos.left > (otherPos.left + otherPos.width) || otherPos.left > (curPos.left + curPos.width))
                continue;

            // has vertical gap
            if (curPos.top > (otherPos.top + otherPos.height) || otherPos.top > (curPos.top + curPos.height))
                continue;
            printf("Aie\n");
        }
    }
}

void Etage::update()
{
    if(this->m_elapsed.asSeconds() >= frametime)
    {

        checkCollisionsDmg(this->joueur);
        // Do something 60 times a second.
        this->joueur->update(checkCollisionsX(joueur), checkCollisionsY(joueur));

        this->m_elapsed -= sf::seconds(frametime); // Subtracting.
    }
};

sf::Time Etage::GetElapsed()
{
    return m_elapsed;
}

void Etage::RestartClock()
{
    m_elapsed += m_clock.restart();
}
