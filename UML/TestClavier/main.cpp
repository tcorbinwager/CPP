
#include <iostream>
#include "clavier.h"

using namespace std;

int main()
{
    TOUCHES_CLAVIER test;
    int valeur;
    Clavier touche;

    do{

        test = touche.ScruterClavier();

        if(test != AUCUNE){
            switch (test) {
                case PLUS: valeur = PLUS;
                        cout << valeur << endl;
                break;
                case MOINS:valeur = MOINS;
                        cout << valeur << endl;
                break;
                case MODE: valeur=MODE;
                        cout << valeur << endl;
                break;
            }
        }

    }while(test != FIN);

    return 0;
}
