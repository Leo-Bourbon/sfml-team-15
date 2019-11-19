#ifndef ETAGE_H
#define ETAGE_H

#include "Salle.h"
#include <vector>

class Etage
{
    public:
        Etage(std::vector<Salle> listeSalles);
        virtual ~Etage();

        std::vector<Entite> listeEntites;

        void genererEtage();
        Salle* salles[6];

        void afficherSalle();
        void afficherEntites();
        void afficher();

    protected:

    private:
};

#endif // ETAGE_H
