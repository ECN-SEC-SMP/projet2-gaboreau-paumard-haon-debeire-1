#ifndef __plateau_hpp
#define __plateau_hpp

#include <vector>
#include <iostream>
#include <string>
#include "macro.hpp"
#include "tortue.hpp"
#include "carte.hpp"

using namespace std;

class plateau
{
public:

   plateau(){};
   plateau(vector<tortue*> tortue);
  // void addTortue(tortue* tortue);
   void affichePlateau();
   bool moveTortue(tortue* LaTortue,int deplacement);
   void initPlateau(vector<tortue*>);
   
   tortue* isWinner();
   

private:
   vector<vector<tortue*>> lePlateau;
   vector<tortue*> listeTortues;
};

#endif