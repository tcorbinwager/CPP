#include <iostream>
#include "jeu2048.h"

using namespace std;

void AfficherGrille(Jeu2048 _lejeu);

void AfficherGrille(Jeu2048 _lejeu){
    int _grille[4][4];

    _lejeu.ObtenirGrille(_grille);
    cout << "Score : " << _lejeu.ObtenirScore() << " | Nombre de coups : " << _lejeu.ObtenirNbCoups() <<endl;
    cout << "+"<< setfill('-') << setw(6) << "+"<< setw(6) << "+" << setw(6) << "+"<< setw(6) << "+" <<endl;

    for(int i=0; i<4; i++){
        for(int n=0; n<4; n++){
            cout << setfill(' ');
            if(_grille[i][n]!=0){
                cout << "|"<< setw(5)<<_grille[i][n];
            }else
                cout << "|"<< setw(6);

        }
        cout << "|" << endl;
        cout << "+"<< setfill('-') << setw(6) << "+"<< setw(6) << "+" << setw(6) << "+"<< setw(6) << "+" <<endl;

    }


}

int main()
{
    bool Fin;
    char _deplacement;
    Jeu2048 leJeu;
    int grilleTest[4][4];
    int partie;


        do{
            AfficherGrille(leJeu);
            do{
            cout << "Votre déplacement : H (haut), B (bas), D (droite) , G (gauche), F (fin partie) : ";
            cin >> _deplacement;
            _deplacement = toupper(_deplacement);
            }while(_deplacement!='H' && _deplacement!='D' && _deplacement!='B' && _deplacement!='G' && _deplacement!='F');
            Fin = leJeu.JouerCoup(_deplacement);

        }while(!Fin && _deplacement!='F');
    leJeu.ObtenirGrille(grilleTest);
    for(int i=0;i<4;i++){
        for(int n=0;n<4;n++){
            if(grilleTest[i][n]==2048)
                partie=0;
            else
                partie=1;

        }
    }
    if(partie==0)
        cout << "Partie Gagnée" << endl;
    else
        cout << "Partie perdue" << endl;



    return 0;
}
