#include "Entite.hpp"
#include <stdio.h>

Entite::Entite() {
}

Entite::Entite(Vector2f position, Vector2f taille) {
    //ctor
    forme = RectangleShape(taille);
    forme.setOrigin(Vector2f(0, forme.getGlobalBounds().height));
    forme.setPosition(position);
    forme.setOutlineThickness(1);
    forme.setOutlineColor(sf::Color::White);
}

Entite::~Entite() {
    //dtor
}

void Entite::afficher(RenderWindow &window) {
    window.draw(this->forme);
}

void Entite::deplacer() {
}

void Entite::setTexture(Texture &texture) {
    this->forme.setTexture(&texture);
}

Vector2f Entite::getPosition() {
    position = this->forme.getPosition();
    return this->position;
}

void Entite::setPosition(Vector2f newPosition) {
    this->position = Vector2f(newPosition);
    this->forme.setPosition(newPosition);
}

Vector2f Entite::getTaille() {
    taille = this->forme.getSize();
    return this->taille;
}

void Entite::setTaille(Vector2f newTaille) {
    this->taille = Vector2f(newTaille);
    this->forme.setSize(newTaille);
}
