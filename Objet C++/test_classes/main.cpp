#include <iostream>
#include "ipv4.h"

using namespace std;

void AfficherTableau(unsigned char *tab);

int main()
{
    unsigned char adresse[4] = {192, 168, 1, 1};
    unsigned char masque[4];
    unsigned char reseau[4];
    unsigned char diffusion[4];
    unsigned char premiere[4];
    unsigned char derniere[4];

    Ipv4 uneAdresse(adresse, 24); //instanciation de la classe IPv4

    cout << "Adresse IPv4 : ";
    AfficherTableau(adresse);
    uneAdresse.ObtenirMasque(masque);
    cout << "Masque : ";
    AfficherTableau(masque);
    uneAdresse.ObtenirAdresseReseau(reseau);
    cout << "Réseau : ";
    AfficherTableau(reseau);
    uneAdresse.ObtenirAdresseDiffusion(diffusion);
    cout << "Diffusion : ";
    AfficherTableau(diffusion);
    cout << endl;
    uneAdresse.ObtenirPremiereAdresse(premiere);
    cout << "Première adresse du réseau : ";
    AfficherTableau(premiere);
    uneAdresse.ObtenirDerniereAdresse(derniere);
    cout << "Dernière adresse du réseau : ";
    AfficherTableau(derniere);
    cout << "Sur le réseau, il y a " << uneAdresse.ObtenirNombreMachines() << " machines" << endl;

    return 0;
}

void AfficherTableau(unsigned char *tab)
{
    for (int i = 0 ; i < 4 ; i++) {
        cout << static_cast<int>(tab[i]);
        if(i < 3){
            cout << ".";
        }
    }
    cout << endl;
}
