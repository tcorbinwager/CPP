#include "horloge.h"



Horloge::Horloge(int _nbMode, int _resolution):
    heures(0),
    minutes(0),
    resolution(_resolution),
    mode(AUCUN_REGLAGE),
    nbModes(_nbMode)

{
    leClavier = new Clavier;
    leCadran = new Cadran(5,5,1,7,BLANC,ROUGEP);
    valAvant = time(NULL);
}

Horloge::~Horloge()
{
    delete leCadran;
    delete leClavier;
}

bool Horloge::AvancerHeures()
{
    bool retour = false;
        if(resolution == 24){
            if(heures == 23){
                retour = true;
                heures = 0;
            }else{
                heures++;
            }
        }else{
            if(heures == 12){
                retour = true;
                heures = 1;
            }else{
                heures++;
            }
        }
        return retour;
}

bool Horloge::AvancerMinutes()
{
    bool retour = false;
        if(minutes == 59){
            retour = true;
            minutes = 0;
        }else{
            minutes++;
        }
        return retour;
}

void Horloge::ReculerHeure()
{
    if(resolution == 24){
            if(heures == 0){
                heures = 23;
            }else{
                heures--;
            }
        }else{
            if(heures == 1){
                heures = 12;
            }else{
                heures--;
            }
        }

}

void Horloge::ReculerMinutes()
{
    if(minutes == 0){
            minutes = 59;
        }else{
            minutes--;
        }
}

void Horloge::ChangerMode()
{
    mode = (mode + 1) %nbModes;
}

void Horloge::ActualiserHeure(){
    time_t valCourante = time(NULL);
    double seconde = difftime(valCourante,valAvant);
    if(seconde > 1) // à modifier pour aller plus vite pendant le test
    {
        valAvant = valCourante;
        if(AvancerMinutes())
            AvancerHeures();
    }
}

TOUCHES_CLAVIER Horloge::Controler(TOUCHES_CLAVIER _laTouche)
{
    _laTouche = leClavier->ScruterClavier();
    if(_laTouche == MODE){
        ChangerMode();
    }

    switch (mode) {
    case AUCUN_REGLAGE : ActualiserHeure();
        leCadran->Afficher(heures, 1);
        leCadran->Afficher(minutes, 4);
        break;
    case REGLAGE_HEURES : if(_laTouche == PLUS){
            AvancerHeures();
        }else{
            if(_laTouche == MOINS){
                ReculerHeure();
            }
        }
        leCadran->Afficher("HH", 1);
        leCadran->Afficher(heures, 4);
        break;
    case REGLAGE_MINUTES : if(_laTouche == PLUS){
            AvancerMinutes();
        }else{
            if(_laTouche == MOINS){
                ReculerMinutes();

            }
        }
        leCadran->Afficher("MM", 1);
        leCadran->Afficher(minutes, 4);
        break;

    }
    return _laTouche;
}
