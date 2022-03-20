#include "carte.hpp"

carte::carte(string couleur,string action)
{
    this->couleur = couleur;
    this ->action = action;
}

carte::carte()
{
    this->action = "blank";
    this->couleur = "blank";
}

void carte::set_action(string action)
{
    this->action = action;
}

void carte::set_couleur(string couleur)
{
    this-> couleur = couleur;
}

string carte::get_couleur()
{
    return this->couleur;
}

string carte::get_action()
{
    return this->action;
}