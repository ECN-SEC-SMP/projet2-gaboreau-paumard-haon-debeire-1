#include "partie.hpp"
#include "plateau.hpp"

partie::partie()
{

    vector<string> color;
    color.push_back("rouge");
    color.push_back("vert");
    color.push_back("jaune");
    color.push_back("bleu");
    color.push_back("violet");

    this->tortues = vector<tortue*>();
    for (int i = 0; i < 5; i++)
    {
        this->tortues.push_back(new tortue(color[i]));
    }

    vector<tortue*> tortueBuffer = this->getTortues();
    this->lePlateau = plateau(tortueBuffer);

    this->laPioche = pioche();
    
    // création des joueurs
    this->nbJoueurHumain = 0;

    do
    {
        cout << "Combien de joueur humain: ";
        cin >> nbJoueurHumain;
    } while (nbJoueurHumain < 2 || nbJoueurHumain > 5);

    this->joueurs = vector<joueur *>();

    // création des joueurs humains
    humain *bufferHumain = nullptr;
    for (int i = 0; i < nbJoueurHumain; i++)
    {
        bufferHumain = new humain();
        this->joueurs.push_back(bufferHumain);
    }

    // création des ia
    ia *bufferIA = nullptr;
    for (int i = 0; i < (5 - nbJoueurHumain); i++)
    {
        bufferIA = new ia();
        this->joueurs.push_back(bufferIA);
    }

    this->currentJoueur = this->joueurs.begin();

}

tortue* partie::getTortueByColor(string color) 
{
    tortue* toReturn = nullptr;

    for (int i = 0; i < 5; i++)
    {
        if (this->tortues[i]->get_color() == color)
        {
            toReturn = this->tortues[i];
        } 
    }

    return toReturn;  
}

void partie::run()
{
    this->initManche();

    bool continuer = true;

    carte carteJoue;
    bool carteJoueeImpossible = true;
    tortue* objectDeMouvement;
    int mouvement;

    int i = 1;
    while (continuer)
    {
        this->lePlateau.affichePlateau();

        cout << "joueur n°" << i << " à toi de jouer! " << endl;

        do
        {

            carteJoue = (*this->currentJoueur)->update();
            objectDeMouvement = this->getTortueByColor(carteJoue.get_couleur());
            mouvement = this->convertStringActionToInt(carteJoue.get_action());
            carteJoueeImpossible = this->lePlateau.moveTortue(objectDeMouvement, mouvement);

        } while (carteJoueeImpossible);
        
        (*this->currentJoueur)->removeCarte(carteJoue);
        (*this->currentJoueur)->piocheUneCarte(this->laPioche);

        cout << "check winner" << endl;
        this->checkWinner();
        cout << "nextJoueur" << endl;
        this->nextJoueur();
        i = (i==5) ? 1 : i+1; // ternary operator pour la classe!
        cout << "on boucle" << endl;

        sleep(4);
        std::system("clear");
    }
}

int partie::convertStringActionToInt(string action) {

    int movement = 0;

    if (action == "avance de 1")
    {
        movement = 1;
    } else if (action == "avance de 2")
    {   
        movement = 2;
    } else if (action == "recul de 1")
    {
        movement = -1;
    }
    
    return movement;
    
}

void partie::setJoueurs(vector<joueur *> joueurs)
{
    this->joueurs = joueurs;
}

vector<joueur *> partie::getJoueurs()
{
    return this->joueurs;
}

void partie::nextJoueur()
{
    this->currentJoueur++;

    if (this->currentJoueur == this->joueurs.end())
    {
        this->currentJoueur = this->joueurs.begin();
    }
}

void partie::setCurrentJoueur(vector<joueur *>::iterator joueur)
{
    if (joueur > this->joueurs.begin() && joueur < this->joueurs.end())
    {
        this->currentJoueur = joueur;
    }
}

vector<joueur *>::iterator partie::getCurrentJoueur()
{
    return this->currentJoueur;
}

void partie::setPlateau(plateau plateau)
{
    this->lePlateau = plateau;
}

plateau partie::getPlateau()
{
    return this->lePlateau;
}

void partie::setPioche(pioche pioche)
{
    this->laPioche = pioche;
}

pioche partie::getPioche()
{
    return this->laPioche;
}

joueur *partie::isWinner()
{
    return nullptr;
}

bool partie::checkWinner()
{
    tortue *winnerManche = nullptr;
    joueur *winnerPartie = nullptr;

    bool continuer = true;

    winnerManche = this->lePlateau.isWinner();
    if (winnerManche != nullptr)
    {
        // on ajouter un salade au joueur gagnant
        winnerPartie = this->isWinner();
        if (winnerPartie != nullptr)
        {
            // on a un gagnant !
            // afficher le nom du gagnant
            continuer = false;
        }
    }

    return continuer;
}

vector<tortue*> partie::getTortues() {
    return this->tortues;
}

void partie::initManche()
{
    // deck aléatoire pour chaque joueur
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            this->joueurs[i]->addCarte( this->laPioche.piocheCarte_rand() );
        }
    }
    
    // attribution des tortues à chaque joueur
    this->shuffleTortues();
    this->shuffleJoueurs();
    for (int i = 0; i < 5; i++)
    {
        this->joueurs[i]->set_tortue( this->tortues[i] );
    }

    // création d'une pile de tortue aléatoire sur case 1
    this->lePlateau.initPlateau(this->tortues);
}


void partie::shuffleTortues()
{
    unsigned seed = std::chrono::system_clock::now()
                        .time_since_epoch()
                        .count();
    shuffle(this->tortues.begin(), this->tortues.end(), std::default_random_engine(seed));
    
}

void partie::shuffleJoueurs()
{
    unsigned seed = std::chrono::system_clock::now()
                        .time_since_epoch()
                        .count();
    shuffle(this->joueurs.begin(), this->joueurs.end(), std::default_random_engine(seed));
}
 