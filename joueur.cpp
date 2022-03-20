#include "joueur.hpp"

// joueur::joueur() {}

/*joueur::joueur(tortue *maTortue, vector<carte> deck)
{
    this->tortueJoueur = maTortue;
    this->deck = deck;
    this->nbSalade = 0;
}*/

// deck

vector<carte> *joueur::getDeck()
{
    return &this->deck;
}

void joueur::setDeck(vector<carte> deck)
{
    this->deck = deck;
}

// carte
void joueur::addCarte(carte new_card)
{
    this->deck.push_back(new_card);
}

void joueur::removeCarte(int cardIndex)
{
    vector<carte>::iterator it;
    it = this->deck.begin() + cardIndex;
    this->deck.erase(it);
}

void joueur::removeCarte(carte carteToRemove)
{
    vector<carte>::iterator carteIt;

    for (carteIt = this->deck.begin(); carteIt < this->deck.end(); carteIt++)
    {
        if ((*carteIt) == carteToRemove)
        {
            this->deck.erase(carteIt);
        }
        
    }
    
}

void joueur::piocheUneCarte(pioche pioche)
{
    this->addCarte(pioche.piocheCarte_rand());
}

// salade
int joueur::getNbSalade()
{
    return this->nbSalade;
}

void joueur::setNbSalade(int nb)
{
    this->nbSalade = nb;
}

void joueur::incrementSalade()
{
    this->nbSalade++;
}

tortue *joueur::get_tortue()
{
    return this->maTortue;
}
void joueur::set_tortue(tortue *Latortue)
{
    this->maTortue = Latortue;
}