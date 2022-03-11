#ifndef _JOUEUR_HPP_
#define _JOUEUR_HPP_
#include <iostream>
#include "tortue.h"
#include "carte.h"
using namespace std;


class joueur{
private :
  vector<carte> deck;
  tortue_joueur *Tortue;

public:

    void setX(T x);
    void setY(T y);
    T getX() const;
    T getY() const;
    
};




#endif