#include "plateau.hpp"

plateau::plateau(vector<tortue*> tortues) {

    this->listeTortues = tortues;
    this->lePlateau = vector<vector<tortue*>>();

    for (long unsigned int i = 0; i < 10; i++)
    {
        this->lePlateau.push_back(vector<tortue*>());
    }

    for (long unsigned int t = 0; t < 5; t++)
    {
        this->lePlateau[t].push_back(new tortue());
    }
    
}

/*tortue* plateau::isWinner()
{
    if(this->lePlateau.end()->size() != 0)
    {
        //return this->lePlateau.end()->begin();
    }
}*/


void plateau::affichePlateau()
{

    vector<vector<tortue*>>::iterator itX;
    vector<tortue*>::iterator itY;

    cout << "---DEPART---" << endl;

    for (itX = this->lePlateau.begin(); itX < this->lePlateau.end(); itX++)
    {
        for (itY = (*itX).begin(); itY < (*itX).end(); itY++)
        {
            cout << (*itY)->get_color()[0] << endl;
        }
    }

    cout << "---FIN---" << endl;
}

tortue* plateau::isWinner()
{
    return nullptr;
}

bool plateau::moveTortue(tortue* LaTortue,int deplacement)
{
    cout << "move" << endl;
    
    bool boolMoveAccepted = false;

    vector<tortue*> tortueToMove = vector<tortue*>();

    vector<vector<tortue*>>::iterator itX;
    vector<tortue*>::iterator itY;

    int posX = 0; // position de la tortue en X
    int posY = 0; // position de la tortue en Y
    vector<vector<tortue*>>::iterator itPosX;
    vector<tortue*>::iterator itPosY;


    for (itX = this->lePlateau.begin(); itX < this->lePlateau.end(); itX++)
    {
        for (itY = (*itX).begin(); itY < (*itX).end(); itY++)
        {
            if ((*itY) == LaTortue)
            {
                posX = itX - this->lePlateau.begin();
                itPosX = itX;
                posY = itY - (*itX).begin();
                itPosY = itY;
            }
        }
    }

    cout << "posX + dep = " << posX + deplacement << "avec posX et deplacement" << posX << " " << deplacement << endl;
    if (posX + deplacement < 0 || posX + deplacement > 10)
    {

        boolMoveAccepted = true;

        tortueToMove = vector<tortue*>(itPosY, (*itPosX).end());

        (*itPosX).erase(tortueToMove.begin(), tortueToMove.end());
        (*(itX + deplacement)).insert((*(itX + deplacement)).end(), tortueToMove.begin(), tortueToMove.end());

    } else {

        boolMoveAccepted = false;

    }

    return boolMoveAccepted;
    
    /*vector<tortue*> tortueToMove;
    vector<tortue*>::iterator itVec;
    int buffX = LaTortue->get_posCase();

    for(long unsigned int i = 0;i<this->lePlateau[LaTortue->get_posCase()].size();i++)
    {
        tortueToMove.push_back(this->lePlateau[LaTortue->get_posCase()][i+LaTortue->get_posCase()]);
    }
    //copier le buffer de tortue à bouger
    for(long unsigned int i =0;i<tortueToMove.size() ;i++)
    {
        
        this->lePlateau[buffX+deplacement].push_back(tortueToMove[i]);
    }*/

    cout << "endmove" << endl;
}

void plateau::initPlateau(vector<tortue*> pileTortue)
{
    vector<vector<tortue*>>::iterator it;

    for(it = this->lePlateau.begin();it!=this->lePlateau.end();it++)
    {
        this->lePlateau.erase(it);
    }

    it = this->lePlateau.begin();
    for (int i = 0; i < pileTortue.size(); i++)
    {
        (*it).push_back(pileTortue[i]);
    }
}