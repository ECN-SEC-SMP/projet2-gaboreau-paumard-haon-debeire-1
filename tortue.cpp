#include "tortue.hpp"


tortue::tortue()
{
    
}

tortue::tortue(string color) {

    this->couleur = color;

}

string tortue::get_color()
{
    return this->couleur;
}

int tortue::get_posCase()
{
    return this->posCase;
}

int tortue::get_posPile()
{
    return this->posPile;
}

void tortue::set_color(string color)
{
    this ->couleur = color;
}


void tortue::set_posCase(int nb_case)
{
    this->posCase = nb_case;
}

void tortue::set_posPile(int nb_pile)
{
    this->posCase = nb_pile;
}