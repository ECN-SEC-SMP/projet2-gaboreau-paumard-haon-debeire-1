#include "ia.hpp"

carte *ia::bestCardToPlay()
{
    // récupération des informations nécessaire
    int x = this->get_tortue()->get_posCase();
    //int y = this->get_tortue()->get_posPile();

    // - récupération des cartes qui concerne ma tortue
    vector<carte> deck = *this->getDeck();
    vector<carte *> mesCartes;
    for (int i = 0; i < 5; i++)
    {
        if (deck[i].get_couleur() == this->get_tortue()->get_color())
        {
            mesCartes.push_back(&deck[i]);
        }
    }
    vector<carte *> pasMesCartes;
    for (int i = 0; i < 5; i++)
    {
        if (deck[i].get_couleur() != this->get_tortue()->get_color())
        {
            pasMesCartes.push_back(&deck[i]);
        }
    }

    //srand(time(NULL));
    //int randomi = rand() % 5;
    srand(time(NULL));
    int randomBluff = rand() % 1;

    // choix de la carte à jouer
    if (x < 6)
    { // encore le temps de bluffer

        if (randomBluff)
        { // choix du bluff
            if (pasMesCartes.size()) {
                return pasMesCartes[rand() % pasMesCartes.size()];
            } else {
                return mesCartes[rand() % mesCartes.size()];
            }
            
        }
        else
        { // choix du ok

            if (mesCartes.size())
            {
                return mesCartes[rand() % mesCartes.size()];
            }
            else
            {
                return pasMesCartes[rand() % pasMesCartes.size()];
            }
        }
    }
    else
    { // pas le temps de bluffer

        if (mesCartes.size())
        {
            return mesCartes[rand() % mesCartes.size()];
        }
        else
        {
            return pasMesCartes[rand() % pasMesCartes.size()];
        }
    }
}

/*void update()
{
    cout << "je suis une ia bordel!" << endl;
}*/