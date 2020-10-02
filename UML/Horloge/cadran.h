
#ifndef CADRAN_H
#define CADRAN_H

#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <cstring>

 enum Police{
    NOIRP=30,
     ROUGEP,
     VERTP,
     JAUNEP,
     BLEUP,
     MAGENTAP,
     CYANP,
     BLANCP,

};

 enum Fond{
   NOIR=40,
     ROUGE,
     VERT,
     JAUNE,
     BLEU,
     MAGENTA,
     CYAN,
     BLANC,

 };

using namespace std;

class Cadran
{
public:
    Cadran(const int _posX=1,const int _posY=1,const int _hauteur=1,const int _largeur=7,enum Fond _unFond=BLANC, enum Police _couleur=ROUGEP);
    ~Cadran();
    void Afficher(const string _texte, const int _position=0, const int _test=0);
    void Afficher(const int _valeur, const int _position=0, const int _test=0);
    void Effacer();
private:
    void PositionnerCurseur(const int _posx, const int _posy);
    int posX;   /// coordonnée en X du premier caractère dans le cadran
    int posY;   /// coordonnée en Y du premier caractère dans le cadran
    int hauteur;    /// nombre de lignes du cadran
    int largeur;    /// nombre de caractères par ligne
    enum Fond leFond;
    enum Police couleurPolice;
};

#endif // CADRAN_H
