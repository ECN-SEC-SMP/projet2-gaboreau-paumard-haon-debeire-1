#ifndef __joueur_hpp
#define __joueur_hpp

#include <vector>
#include <iostream>
#include <string>
#include "pioche.hpp"
#include "macro.hpp"
#include "carte.hpp"
#include "tortue.hpp"

using namespace std;

class joueur
{
public:
   
   joueur(){}
   //joueur(tortue*,vector<carte> deck);

   // deck
   void setDeck(vector<carte> deck);
   vector<carte>* getDeck();

   // carte
   void piocheUneCarte(pioche pioche);
   void addCarte(carte);
   void removeCarte(int cardIndex);
   void removeCarte(carte carteToRemove);

   // salade
   int getNbSalade();
   void setNbSalade(int nb);
   void incrementSalade();

   tortue * get_tortue();
   void set_tortue(tortue*);

   virtual carte update() = 0;

   ~joueur(){}

private:

   vector<carte> deck;
   int nbSalade;
   tortue * maTortue;
   
};



    


#endif