#ifndef __tortue_hpp
#define __tortue_hpp

#include <vector>
#include <iostream>
#include <string>

#include "macro.hpp"

using namespace std;

class tortue
{
public:
    tortue();
    tortue(string color);

    string get_color();
    int get_posCase();
    int get_posPile();
    
    void set_color(string color);
    void set_posCase(int);
    void set_posPile(int);


private:

string couleur;
int posCase;
int posPile;


   
};

#endif