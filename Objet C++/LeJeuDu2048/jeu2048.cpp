#include "jeu2048.h"

Jeu2048::Jeu2048(): nbCoups(0) , score(0)

{

    srand(time(nullptr));

    for(int i=0;i<4;i++){
        for(int n=0;n<4;n++){
            grille[i][n]=0;
        }
    }

    PlacerNouvelleTuille();
}



int Jeu2048::TirerAleatoire(MODE_ALEATOIRE _mode){

    int valeur=0;

    if(_mode==POSITION){
        valeur = (rand() %4);
    }
    if(_mode==TUILE){
        valeur = (((rand() %2) +1) *2);
    }

    return valeur;
}



void Jeu2048::PlacerNouvelleTuille(){
    int li=0;
    int co=0;

    do{
         li = TirerAleatoire(POSITION);
         co = TirerAleatoire(POSITION);
    }while(grille[li][co] !=0);

    grille[li][co]=TirerAleatoire(TUILE);
}



void Jeu2048::ObtenirGrille(int _grille[][4]){

    for(int i=0;i<4;i++){
        for(int n=0;n<4;n++){
            _grille[i][n]=grille[i][n];
        }
    }

}

void Jeu2048::CalculerScore(){
    score=0;

    for(int i=0;i<4;i++){
        for(int n=0;n<4;n++){
            score += grille[i][n];
        }
    }
}

int Jeu2048::ObtenirScore(){

    CalculerScore();
    return score;
}



int Jeu2048::ObtenirNbCoups(){
    return nbCoups;
}

void Jeu2048::Calculer(){

    switch (direction) {
        case 'G':
            for(int ligne=0; ligne<4 ;ligne++){
                for(int colonne=0; colonne<4-1; colonne++){
                    if(grille[ligne][colonne] == grille[ligne][colonne+1]){
                        grille[ligne][colonne] = grille[ligne][colonne]*2;
                        grille[ligne][colonne+1]=0;
                    }
                }
            }
        break;
    case 'D':
        for(int ligne=0; ligne<4 ;ligne++){
            for(int colonne=0; colonne<4-1; colonne++){
                if(grille[ligne][colonne+1] == grille[ligne][colonne]){
                    grille[ligne][colonne+1] = grille[ligne][colonne]*2;
                    grille[ligne][colonne]=0;
                }
            }
        }
        break;
    case 'B':
        for(int colonne=0; colonne<4 ;colonne++){
            for(int ligne=0; ligne<4-1; ligne++){
                if(grille[ligne+1][colonne] == grille[ligne][colonne]){
                    grille[ligne+1][colonne] = grille[ligne][colonne]*2;
                    grille[ligne][colonne]=0;
                }
            }
        }
        break;
    case 'H':
        for(int colonne=0; colonne<4 ;colonne++){
            for(int ligne=0; ligne<4-1; ligne++){
                if(grille[ligne][colonne] == grille[ligne+1][colonne]){
                    grille[ligne][colonne] = grille[ligne][colonne]*2;
                    grille[ligne+1][colonne]=0;
                }
            }
        }
        break;
    }

}

void Jeu2048::Deplacer(){
    for(int x=0; x<4; x++){
        switch (direction) {
            case 'G':
                for(int ligne=0; ligne<4 ;ligne++){
                    for(int colonne=0; colonne<4-1; colonne++){
                        if(grille[ligne][colonne] == 0){
                            grille[ligne][colonne] = grille[ligne][colonne+1];
                            grille[ligne][colonne+1]=0;
                        }
                    }
                }
            break;
        case 'D':
            for(int ligne=0; ligne<4 ;ligne++){
                for(int colonne=0; colonne<4-1;colonne++){
                    if(grille[ligne][colonne+1] == 0){
                        grille[ligne][colonne+1] = grille[ligne][colonne];
                        grille[ligne][colonne]=0;
                    }
                }
            }
            break;
        case 'B':
            for(int colonne=0; colonne<4 ;colonne++){
                for(int ligne=0; ligne<4-1; ligne++){
                    if(grille[ligne+1][colonne] == 0){
                        grille[ligne+1][colonne] = grille[ligne][colonne];
                        grille[ligne][colonne]=0;
                    }
                }
            }
            break;
        case 'H':
            for(int colonne=0; colonne<4 ;colonne++){
                for(int ligne=0; ligne<4-1; ligne++){
                    if(grille[ligne][colonne] == 0){
                        grille[ligne][colonne] = grille[ligne+1][colonne];
                        grille[ligne+1][colonne]=0;
                    }
                }
            }
            break;
        }
    }
}

bool Jeu2048::RechercherFinDePartie(){
    bool fin=0;
    int cpt=0;
    for(int i=0; i<4; i++){
        for(int n=0; n<4; n++){
            if(grille[i][n]==2048){
                fin= 1;
            }
            if(grille[i][n]==0)
                cpt++;
        }
    }
    if(cpt==0)
        fin=1;

    return fin;
}

bool Jeu2048::JouerCoup(char _direction)
{
    direction =_direction;
    nbCoups++;
    Deplacer();
    Calculer();
    Deplacer();
    CalculerScore();
    bool fin = RechercherFinDePartie();
    if(!fin){
        PlacerNouvelleTuille();
        system("clear");
    }
    return fin;
}
