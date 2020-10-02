#ifndef MENU_H
#define MENU_H

#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iostream>

using namespace std;

class Menu
{
private:
    string nom;
    string * options;
    int nbOptions;
    int longueurMax;
public:
    Menu(const string &_nom);
    ~Menu();
    int Afficher();
    static void AttendreAppuiTouche();
};

enum CHOIX_MENU{
    OPTION_1=1,
    OPTION_2,
    OPTION_3,
    OPTION_4,
    QUITTER
};

#endif // MENU_H
