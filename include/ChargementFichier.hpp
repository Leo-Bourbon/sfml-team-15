#ifndef CHARGEMENTFICHIER_HPP_INCLUDED
#define CHARGEMENTFICHIER_HPP_INCLUDED

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "CONSTANTES.hpp"
#include "Salle.h"
#include <vector>

std::vector<Salle> lireSalles(std::string listeSalles);
Salle lireSalle(std::ifstream &fichier);

#endif // CHARGEMENTFICHIER_HPP_INCLUDED
