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

Vector2f Fleche::getNextPos() {
    //return this->position + this->velocite;
}

void Fleche::deplacer(Vector2f direction) {
    this->forme.move(direction);
}

void Fleche::update(){/*
    this->forme.move(moveX ? this->velocite.x : 0, moveY ? this->velocite.y : 0);
    velocite.x = 0;
    velocite.y = 0;*/
}
