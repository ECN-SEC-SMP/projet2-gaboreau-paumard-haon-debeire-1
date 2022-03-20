#include "humain.hpp"

carte humain::update()
{
    cout << "joueur humain, à toi de jouer! choisis parmis tes " << this->getDeck()->size() << " cartes." << endl << endl;

    //1) affiche le deck du joueur
    //2) joeur selectionne carte à jouer
    //3) on enlève carte
    //4) on pioche carte

    vector<carte>::iterator itDeck;
    vector<carte> buffDeck = *this->getDeck();
    carte carteToReturn;
    string choixHumain;
    //int carteChoise = 0;
    bool choixPossible=1;
    for(int i = 1;i<6;i++)
    {
        cout << i << ") " << buffDeck[i-1] << endl;
    }

    cout<<"choisir carte : ";
    cin>>choixHumain;
    do
    {
        if(choixHumain.size() !=1 ||stoi(choixHumain)<1 ||stoi(choixHumain)>5)
        {
            choixPossible = 0;
            cout<<"choix non correct"<<endl<<"veuillez recommencer : ";
            cin>>choixHumain;
        }
        else
        {
            carteToReturn = buffDeck[stoi(choixHumain)-1];
            //this->removeCarte(stoi(choixHumain)); # on valide d'abord dans partie.run si la carte peut être jouée! on supprime après alors
            choixPossible = 1;
        }

    } while (choixPossible == 0);

    return carteToReturn;    
    
}


 