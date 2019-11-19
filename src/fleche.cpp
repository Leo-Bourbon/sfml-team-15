#include "Fleche.hpp"

Fleche::Fleche()
{
    //ctor
    this->vie = 1;
}

Fleche::~Fleche()
{
    //dtor
}

void Fleche::deplacer(Vector2f direction) {
    this->forme.move(direction);

}
