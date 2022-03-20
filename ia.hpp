#ifndef __ia_hpp
#define __ia_hpp

#include <time.h>
#include "joueur.hpp"

using namespace std;

class ia : public joueur
{
public:

    ia() {}
    //ia(tortue* tortue, vector<carte> deck);

    carte* bestCardToPlay();

    virtual carte update() override {
        
        carte carteToPlay = *bestCardToPlay();
        cout << "je suis une ia et je joue la carte " << carteToPlay;
        
        return carteToPlay;

    }

    ~ia(){}
};

#endif