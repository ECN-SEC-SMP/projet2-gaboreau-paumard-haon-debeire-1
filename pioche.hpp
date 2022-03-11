#ifndef _PIOCHE_HPP_
#define _PIOCHE_HPP_
#include <iostream>
using namespace std;


class pioche{
private :

  list <int> cartes;
  int nombre_cartes;

public:

    void pioche_carte_rand();

    void afficheplateau() const;


  //constructeur
    Plateau(int max_x, int max_y);
};








#endif