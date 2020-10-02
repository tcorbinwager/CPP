#ifndef HORLOGE_H
#define HORLOGE_H
#include <time.h>
#include "clavier.h"
#include "cadran.h"

enum MODES_HORLOGES{

    AUCUN_REGLAGE=0,
    REGLAGE_HEURES,
    REGLAGE_MINUTES
};


class Horloge
{
private:
    int heures;
    int minutes;
    const int resolution;
    int mode;
    time_t valAvant;
    const int nbModes;

    Cadran * leCadran;
    Clavier * leClavier;
public:
    Horloge(int _nbMode=3, int _resolution=24);
    ~Horloge();
    bool AvancerHeures();
    bool AvancerMinutes();
    void ReculerHeure();
    void ReculerMinutes();
    void ChangerMode();
    void ActualiserHeure();
    TOUCHES_CLAVIER Controler(TOUCHES_CLAVIER _laTouche);
};

#endif // HORLOGE_H
