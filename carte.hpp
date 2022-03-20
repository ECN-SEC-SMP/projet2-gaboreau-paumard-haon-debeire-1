#ifndef __carte_hpp
#define __carte_hpp

#include <vector>
#include <iostream>
#include <string>
#include "macro.hpp"
#include "tortue.hpp"


using namespace std;


class carte 
{
public:
   carte();
   carte(string couleur,string action);

   void set_couleur(string couleur);
   void set_action(string action);
   string get_couleur(void);
   string get_action(void);

   friend ostream& operator<<(ostream& os, const carte& crt)
   {
      os<<"la tortue "<<crt.couleur<<" "<<crt.action;
      return os;
   }

   bool operator==(const carte b)
   {
      if (this->couleur == b.couleur && this->action == b.action)
      {
         return true;
      } else {
         return false;
      }
      
   }

private:

   string couleur;
   string action;

   
};





#endif