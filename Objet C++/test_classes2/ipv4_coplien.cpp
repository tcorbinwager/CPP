#include "ipv4_coplien.h"

IPv4_coplien::IPv4_coplien()
{
    IPv4_coplien::IPv4_coplien(const unsigned char * _adresse, const unsigned char _cidr)
    {

        adresse= new unsigned char [4];
        masque = new unsigned char [4];
        for(int indice = 0; indice < 4; indice++)
            adresse[indice] = _adresse[indice];
        if(_cidr <= 32)
            CalculerMasque(_cidr);

    }

    IPv4_coplien::IPv4_coplien(const unsigned char * _adresse, const unsigned char * _masque)
    {
        adresse= new unsigned char [4];
        masque = new unsigned char [4];
        for(int indice = 0; indice < 4; indice++){
            adresse[indice] = _adresse[indice];
            masque[indice] = _masque[indice];
        }
    }

    IPv4_coplein::~IPv4_coplien()
    {
        delete [] adresse;
        delete [] masque;
    }

    void IPv4_coplien::CalculerMasque(unsigned char _cidr){
        int indice;
        // Le masque est remis à 0 -> 0.0.0.0
        for(indice=0;indice < 4;indice++)
            masque[indice]=0;

        indice=0;
        //tant que cidr est un multiple de 8
        while(_cidr >= 8){
            masque[indice++] = 255;
            _cidr -= 8;
        }

        //Complement pour la fin du cidr(<8)
        unsigned char puissance = 128;
        while(_cidr-- > 0)//Après test la variable _cidr est décrémentée
        { //Les puissances de 2 sont ajoutées à l'octet par valeur décroissante
            masque[indice] +=puissance;
            puissance /= 2;
        }
    }

    void IPv4_coplien::ObtenirMasque(unsigned char *_masque){
        for(int indice = 0;indice < 4; indice++)
            _masque[indice]= masque[indice];
    }

    void IPv4_coplien::ObtenirAdresseReseau(unsigned char *_reseau){
        for(int indice=0; indice < 4; indice++)
            _reseau[indice] = adresse[indice] & masque[indice];
    }

    void IPv4_coplien::ObtenirAdresseDiffusion(unsigned char *_diffusion){
        unsigned char adresseDuReseau[4];
        ObtenirAdresseReseau(adresseDuReseau);
        for(int indice=0; indice < 4; indice++)
           _diffusion[indice] = adresseDuReseau[indice] | ~masque[indice];
    }


}
