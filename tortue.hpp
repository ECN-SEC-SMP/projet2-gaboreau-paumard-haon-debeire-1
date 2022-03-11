#ifndef __tortue_hpp
#define __tortue_hpp

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Tortue
{
public:
	Tortue();
	Tortue(int posX, int posY, string couleur);

	int getX();
	int getY();
	string getCouleur();

	//friend ostream &operator<<(ostream &out, Tortue &P);

protected:
	string couleur;
	int posX;
	int posY;
};

/* ostream &operator<<(ostream &out, Tortue &P)
{

  out << "Tortue n°" << P.getCouleur() << " :" << endl;
  out << "Position : (" << P.getX() << " ; " << P.getY() << ")"<< endl; 

  return out;
} */

#endif