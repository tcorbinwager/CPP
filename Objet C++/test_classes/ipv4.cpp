#include "ipv4.h"
#include <iostream>
#include <math.h>

using namespace std;

Ipv4::Ipv4(const unsigned char * _adresse, const unsigned char _cidr){
    adresse = new unsigned char [4];
    masque = new unsigned char [4];
    for (int i = 0 ; i < 4; i++) {
        adresse[i] = _adresse[i];
    }
    if (_cidr <= 32) {
        CalculerMasque(_cidr);
    }
}

Ipv4::Ipv4(const unsigned char * _adresse, const unsigned char * _masque){
    adresse = new unsigned char [4];
    masque = new unsigned char [4];
    for (int i = 0 ; i < 4; i++) {
        adresse[i] = _adresse[i];
        masque[i] = _masque[i];
    }
}

Ipv4::~Ipv4(){
    delete [] adresse;
    delete [] masque;
}

void Ipv4::CalculerMasque(unsigned char _cidr){
    int i;
    //Le masque est remis à 0 -> 0.0.0.0
    for (i = 0 ; i < 4 ; i++) {
        masque[i] = 0;
    }
    i = 0;
    //tant que le cidr est multiple de 8
    while (_cidr >= 8) {
        masque[i++] = 255;
        _cidr -= 8;
    }
    //Complément pour la fin du cidr (<8)
    unsigned char puissance = 128;
    while (_cidr-- > 0) { //Après le test la varible _cidr est décrémentée
        //les puissances de 2 sont ajoutées à l'octet par valeur décroissante
        masque[i] += puissance;
        puissance /= 2;
    }
}

void Ipv4::ObtenirMasque(unsigned char *_masque){
    for (int i = 0 ; i < 4 ; i++) {
        _masque[i] = masque[i];
    }
}

void Ipv4::ObtenirAdresseReseau(unsigned char *_reseau){
    for (int i = 0 ; i < 4 ; i++) {
        _reseau[i] = adresse[i] & masque[i];
    }
}

void Ipv4::ObtenirAdresseDiffusion(unsigned char *_diffusion){
    unsigned char adresseDuReseau[4];
    ObtenirAdresseReseau(adresseDuReseau);
    for (int i = 0 ; i < 4 ; i++) {
        _diffusion[i] = adresseDuReseau[i] | ~masque[i]; //~masque[i] est l'inverse du masque donc un 0 devient 1 et inversement
    }
}

void Ipv4::ObtenirPremiereAdresse(unsigned char *_premiereAdresse){
    unsigned char premiere[4];
    ObtenirAdresseReseau(premiere);
    for (int i = 0 ; i < 4 ; i++) {
        _premiereAdresse[i] = premiere[i];
    }
    _premiereAdresse[3] = premiere[3] + 1;
}

void Ipv4::ObtenirDerniereAdresse(unsigned char *_derniereAdresse){
    unsigned char derniere[4];
    ObtenirAdresseDiffusion(derniere);
    for (int i = 0 ; i < 4 ; i++) {
        _derniereAdresse[i] = derniere[i];
    }
    _derniereAdresse[3] = derniere[3] - 1;
}

double Ipv4::ObtenirNombreMachines(){
   unsigned char masq[4];
   double nbMachines = 0;
   double n = 0;
    for (int i = 0 ; i < 4 ; i++) {
        masq[i] = ~masque[i];
    }
    for (int i = 3 ; i >= 0 ; i--) {
        int puissance = 2;
        while (masq[i] > 0) {
            masq[i] -= puissance;
            puissance += puissance;
            n++;
            if (masq[i] == 1) {
                masq[i] -= 1;
                n++;
            }
        }
    }
    nbMachines = pow(2, n);
    return nbMachines-2;
}

