#ifndef JEU2048_H
#define JEU2048_H
#define false 0
#define true 1
#include <math.h>
#include <time.h>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iostream>

enum MODE_ALEATOIRE{
    POSITION,
    TUILE
};


class Jeu2048
{
private:
    int grille[4][4];
    char direction;
    int nbCoups;
    int score;
    int TirerAleatoire(MODE_ALEATOIRE _mode);
    void PlacerNouvelleTuille();
    void Calculer();
    void Deplacer();
    void CalculerScore();
    bool RechercherFinDePartie();

public:
    Jeu2048();
    int win;
    bool JouerCoup(char _direction);
    int ObtenirNbCoups();
    int ObtenirScore();
    void ObtenirGrille(int _grille[][4]);
};


#endif // JEU2048_H
