#include <iterator>
#include <stdlib.h>
#include <time.h>
#include "pioche.hpp"
#include "carte.hpp"

pioche::pioche()
{


}

void pioche::affiche_pioche()
{
    
    vector<carte>::iterator it;

    for(it = this->tas.begin();it<this->tas.end();it++)
    {
        cout<< *it<<endl;
    }
    cout <<"la pioche contient " <<tas.size()<<" cartes"<<endl;
}




  carte pioche::piocheCarte_rand()
  {
    carte buffCart;
    if(this->tas.size() == 0)
    {
        this->construirePioche();
        //cout<<endl<<"remise a zero de la pioche"<<endl;
    }
        
    buffCart.set_action(this->tas.begin()->get_action());
    buffCart.set_couleur(this->tas.begin()->get_couleur());
    this->tas.erase(this->tas.begin());
    return buffCart;
  }





   void pioche::construirePioche()
   {    
    string tab_couleur[] = {rouge,jaune,vert,bleu,violet,multicolor};
    string tab_action[] = {avance1,avance2,recule1,avanceDer1,avanceDer2};
   
    carte buff_carte;

    this->cleanPioche();

//création carte avancer de 1
    for(int i = 0;i<6;i++)
    {
        buff_carte.set_couleur(tab_couleur[i]);
        for(int j = 0;j<5;j++)
        {
            buff_carte.set_action(avance1);
            tas.push_back(buff_carte);
        }
    }

//création carte reculer de 1
    for(int i = 0;i<6;i++)
    {
        buff_carte.set_couleur(tab_couleur[i]);
        for(int j = 0;j<2;j++)
        {
            buff_carte.set_action(recule1);
            tas.push_back(buff_carte);
        }
    }

//création de avance de 2
for(int i = 0;i<5;i++)
{
    buff_carte.set_couleur(tab_couleur[i]);
    buff_carte.set_action(avance2);
    tas.push_back(buff_carte);
}

//création de dernière tortue avance de 1 multicolor
for(int i = 0;i<3;i++)
{
    buff_carte.set_couleur(multicolor);
    buff_carte.set_action(avanceDer1);
    tas.push_back(buff_carte);
}
//création de dernière tortue avance de 2 multicolor
for(int i = 0;i<2;i++)
{
    buff_carte.set_couleur(multicolor);
    buff_carte.set_action(avanceDer2);
    tas.push_back(buff_carte);
}

random_shuffle(this->tas.begin(),this->tas.end());


}

void pioche::cleanPioche()
{
    vector<carte>::iterator it;

    for(it = this->tas.begin();it!=this->tas.end();)
    {
        it = this->tas.erase(it);
        
    }
}

void pioche::affiche_taille_pioche()
{
    cout<<"la pioche contient "<<this->tas.size()<<"cartes";
}