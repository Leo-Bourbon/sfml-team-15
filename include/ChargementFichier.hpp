#ifndef CHARGEMENTFICHIER_HPP_INCLUDED
#define CHARGEMENTFICHIER_HPP_INCLUDED

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "CONSTANTES.hpp"
#include "Salle.hpp"
#include <windows.h>
#include <wincon.h>
#include <vector>

std::vector<Salle> lireSalles(std::string listeSalles);

void afficherSalles(std::vector<Salle> salles, HANDLE h);

#endif // CHARGEMENTFICHIER_HPP_INCLUDED
