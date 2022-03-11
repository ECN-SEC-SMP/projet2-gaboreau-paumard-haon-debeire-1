#include <iostream>
#include "tortue.hpp"

using namespace std;

 // constructeur
Tortue::Tortue() {}

Tortue::Tortue(int posX, int posY, string couleur)
{
	this->posX = NULL;
	this->posY = NULL;
	this->couleur = "";
}

// Accesseur
int Tortue::getX()
{
	return this->posX;
}

int Tortue::getY()
{
	return this->posY;
}

string Tortue::getCouleur()
{
	return this->couleur;
}

