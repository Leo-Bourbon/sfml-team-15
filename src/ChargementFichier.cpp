#include "ChargementFichier.hpp"
#include "Salle.hpp"

std::map<char, TypeEntite> charToType(
{
    {'-', TypeEntite::Sol},
    {'J', TypeEntite::Personnage},
    {'R', TypeEntite::Rocher},
    {'C', TypeEntite::CSouris},
    {'S', TypeEntite::Slimy},
    {'I', TypeEntite::Item}
}
);

using namespace std;

std::vector<Salle> lireSalles(std::string fichierSalles)
{
    std::vector<Salle> listeSalles;

    ifstream fichier;

    fichier.open(fichierSalles.c_str());

    if(!fichier)
    {
        printf("Erreur");
        return listeSalles;
    }

    int nbSalles;

    nbSalles = fichier.get() - '0';
    printf("Nombre de salles :%d\n", nbSalles);


    for(int i = 0; i < nbSalles; i++)
    {
        Salle salle;
        //printf("Salle num : %i\n", i);

        fichier.ignore(1);

        char n = fichier.get();
        salle.setName(n);
        //printf("Nom de la salle : %c\n", n);

        fichier.ignore(1);

        int x = 0;
        int y = 0;
        char c;

        c = fichier.get();
        while (c != '*')
        {
            TypeEntite t;

            if (c == '\n')
            {
                x = 0;
                y += 1;

                c = fichier.get();
                continue;
            }

            t = charToType[c];

            salle.carte[y][x] = t;

            x++;

            c = fichier.get();
        }
        listeSalles.push_back(salle);
    }

    fichier.close();
}
