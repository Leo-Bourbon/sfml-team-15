#ifndef CONSTANTES_HPP_INCLUDED
#include <map>
#define CONSTANTES_HPP_INCLUDED

#define LARGEUR_CASES_SALLE 20
#define HAUTEUR_CASES_SALLE 10

#define LARGEUR_SALLES 3/4
#define HAUTEUR_SALLES 2/3

enum Ecran
{
    Principal, Jeu, Fin
};

enum TypeEntite
{
    Personnage = 0, Sol = 1, Trou = 2, Rocher = 3, CSouris = 4, Slimy = 5, Item = 6
};

enum Directions
{
    Nord = 0, Sud = 1, Est = 2, Ouest = 3
};

#endif // CONSTANTES_HPP_INCLUDED
