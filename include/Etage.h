#ifndef ETAGE_H
#define ETAGE_H

#include "Salle.hpp"
#include "Entite.hpp"
#include "Joueur.hpp"
#include <vector>

class Etage
{
    public:
        Etage(std::vector<Salle> listeSalles, Joueur& joueur);
        virtual ~Etage();

        std::vector<Entite> listeEntites;

        void genererEtage();
        Salle* salles[6];

        void afficherSalle();
        void afficherEntites();
        void afficher();

        void handleInput(sf::Event);
        void update();

        Joueur joueur;

    protected:
    private:
};

#endif // ETAGE_H
