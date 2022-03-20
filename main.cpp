#include <iostream>
#include <string>
#include "carte.hpp"
#include "pioche.hpp"
#include "plateau.hpp"
#include "partie.hpp"
#include "humain.hpp"
using namespace std;

int main()
{

   /*pioche Lapioche;
   Lapioche.construirePioche();

   humain MonHumain;

   for(int i = 0;i<5;i++)
   {
       MonHumain.addCarte(Lapioche.piocheCarte_rand());
   }
 
    cout<<endl<<MonHumain.update()<<endl;*/

    partie laPartie = partie();
    laPartie.run();
    

    return 0;
}