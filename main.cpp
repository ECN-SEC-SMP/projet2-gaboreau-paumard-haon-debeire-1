#include <iostream>
#include "tortue.hpp"

#include <iostream>

using namespace std;

int main() {
  //initialiser tortue
  // initialiser plateau
  // initialiser joueur

  
	cout << endl << "===== Début du programme =====" << endl << endl;
  cout << "Hello World!" << endl << endl;
  // 🐢

	Tortue T1;
	Tortue T2;
	cout << "Position X de T1 : " << T1.getX() << endl;
	cout << "Position Y de T1 : " << T1.getY() << endl;
	cout << "Couleur de T1 : " << T1.getCouleur() << endl;
  return 0;
} 
