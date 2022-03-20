#ifndef __pioche_hpp
#define __pioche_hpp

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include "macro.hpp"
#include "carte.hpp"
using namespace std;


using namespace std;

class pioche
{
public:
   
   pioche();
   carte piocheCarte_rand();
   void construirePioche();
   void affiche_pioche();
   void affiche_taille_pioche();
   void cleanPioche();

/*
   friend ostream& operator<<(ostream& os, pioche carte& pche)
   {
      os<<
      return os;
   }
*/
private:

vector<carte> tas;

   
};



    


#endif