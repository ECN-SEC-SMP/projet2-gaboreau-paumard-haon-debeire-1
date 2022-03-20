#ifndef __partie_hpp
#define __partie_hpp

#include <vector>
#include <iostream>
#include <string>
#include <iterator>
#include <unistd.h>
#include <algorithm>
#include <random>
#include <chrono>

#include "plateau.hpp"
#include "pioche.hpp"
#include "joueur.hpp"
#include "tortue.hpp"
#include "humain.hpp"
#include "ia.hpp"
#include "carte.hpp"

using namespace std;

//class plateau;

class partie
{
public:
    partie();
    partie(int nbHumains);
    void initManche();

    void run();

    void setJoueurs(vector<joueur*> joueurs);
    vector<joueur*> getJoueurs();
    void nextJoueur();

    void setCurrentJoueur(vector<joueur*>::iterator joueur);
    vector<joueur*>::iterator getCurrentJoueur();

    void setPlateau(plateau plateau);
    plateau getPlateau();

    void setPioche(pioche pioche);
    pioche getPioche();

    joueur* isWinner();
    bool checkWinner();

    void shuffleTortues();
    void shuffleJoueurs();

    vector<tortue*> getTortues();
    tortue* getTortueByColor(string color);
    int convertStringActionToInt(string action);

private:
    vector<joueur*> joueurs;
    vector<joueur*>::iterator currentJoueur;
    vector<tortue*> tortues;
    plateau lePlateau;
    pioche laPioche;
    int nbJoueurHumain;
};

#endif