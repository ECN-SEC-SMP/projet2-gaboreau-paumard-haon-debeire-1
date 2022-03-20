#ifndef __humain_hpp
#define __humain_hpp

#include "joueur.hpp"

using namespace std;

class humain : public joueur
{
public:

    humain(){}
    //humain(tortue* tortue, vector<carte> deck);

    void select_card_to_play(void);

    virtual carte update() override;

    ~humain(){}
};

#endif