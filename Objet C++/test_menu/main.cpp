#include <iostream>
#include "Menu.h"
#include "Exception.h"

using namespace std;

int main()
{
    int choix;

    do{
        try {
            Menu leMenu("menu.txt");
            choix= leMenu.Afficher();
            switch(choix){
            case OPTION_1:
                cout << "Vous avez choisi l'option n°1"<<endl;
                Menu::AttendreAppuiTouche();
                break;
            case OPTION_2:
                cout << "Vous avez choisi l'option n°2"<<endl;
                Menu::AttendreAppuiTouche();
                break;
            case OPTION_3:
                cout << "Vous avez choisi l'option n°3"<<endl;
                Menu::AttendreAppuiTouche();
                break;
            case OPTION_4:
                cout << "Vous avez choisi l'option n°4"<<endl;
                Menu::AttendreAppuiTouche();
                break;
            }
        } catch (ErreurIndice const &exp) {
            cout << "Erreur " << exp.ObtenirCodeErreur() << endl;
            cout << exp.ObtenirDescription() << endl;
            exit(EXIT_FAILURE);
        } catch (ErreurOuverture const &exp) {
            cout << "Erreur " << exp.ObtenirCodeErreur() << endl;
            cout << exp.ObtenirDescription() << endl;
            exit(EXIT_FAILURE);
        }

    }while (choix != QUITTER);

    return 0;
}
