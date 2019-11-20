#ifndef ETAGE_H
#define ETAGE_H

#include "Salle.hpp"
#include "Entite.hpp"
#include "Joueur.hpp"
#include "SFML/System/Clock.hpp"
#include <vector>
#include "fonctionsEnnemi.hpp"
#include "fonctionsEnvironnement.hpp"
#include <typeinfo>

class Etage
{
public:
    Etage(std::vector<Salle> listeSalles, RenderWindow* app, std::map<TypeEntite, Texture*>& listeTex);
    virtual ~Etage();

    RenderWindow* fen;

    std::vector<Entite*> listeEntites;
    std::vector<Salle> listeSalles;
    std::map<TypeEntite, Texture*> listeTextures;

    Salle salles[6];
    int salleActuelle;

    void changerSalle(int salle);
    void genererEntitesDeSalle(Salle salle);

    void genererEtage();

    void setJoueur(Joueur* j);

    RectangleShape arrPlan;
    void afficherSalle(sf::RenderWindow& app);
    void afficherEntites(sf::RenderWindow& app);

    void setTexture(Texture& tex);

    void handleInput();
    void update();
    void afficher();

    bool checkCollisionsX(Joueur* e);
    bool checkCollisionsY(Joueur* e);
    void checkCollisionsDmg(Joueur* j);

    void ajouterEntite(Entite* e);

    Joueur* joueur;

    sf::Time GetElapsed();
    void RestartClock();
    sf::Time m_elapsed;

protected:
private:
    sf::Clock m_clock;

    float frametime;
    Texture tex;
};

#endif // ETAGE_H
