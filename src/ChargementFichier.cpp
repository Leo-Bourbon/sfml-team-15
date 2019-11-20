#include "ChargementFichier.hpp"
#include "Salle.hpp"

std::map<char, TypeEntite> charToType( {
    {'-', TypeEntite::Sol},
    {'J', TypeEntite::Personnage},
    {'R', TypeEntite::Rocher},
    {'C', TypeEntite::CSouris},
    {'S', TypeEntite::Slimy},
    {'I', TypeEntite::Item}
}
                                     );

using namespace std;

std::vector<Salle> lireSalles(std::string fichierSalles) {
    std::vector<Salle> listeSalles;

    ifstream fichier;

    fichier.open(fichierSalles.c_str());

    if(!fichier) {
        printf("Erreur");
        return listeSalles;
    }

    int nbSalles;

    nbSalles = fichier.get() - '0';
    printf("Nombre de salles :%d\n", nbSalles);


    for(int i = 0; i < nbSalles; i++) {
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
        while (c != '*') {
            TypeEntite t;

            if (c == '\n') {
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

void afficherSalles(std::vector<Salle> salles, HANDLE hConsole) {
    for (int index = 0; index < salles.size(); index++) {
        printf("Salle %c\n", salles[index].getName());
        for(int j = 0; j < HAUTEUR_CASES_SALLE; j++) {
            for(int i = 0; i < LARGEUR_CASES_SALLE; i++) {
                printf("|");
                switch(salles[index].carte[j][i]) {
                case Personnage:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | BACKGROUND_GREEN);
                    break;
                case Sol:
                    SetConsoleTextAttribute(hConsole, 102);
                    break;
                case Rocher:
                    SetConsoleTextAttribute(hConsole, 136);
                    break;
                case CSouris:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_RED);
                    break;
                case Slimy:
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_RED);
                    break;
                default:
                    break;
                }

                printf("%i", salles[index].carte[j][i]);

                SetConsoleTextAttribute(hConsole, 15);
            }
            printf("|\n");
        }
        printf("\n-------------------\n");
    }
}
