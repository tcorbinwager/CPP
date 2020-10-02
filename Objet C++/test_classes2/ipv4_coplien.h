#ifndef IPV4_COPLIEN_H
#define IPV4_COPLIEN_H


class IPv4_coplien
{
private:
    unsigned char * adresse;
    unsigned char * masque;
    void CalculerMasque(unsigned char _cidr);

public:
    IPv4_coplien(const unsigned char * _adresse, const unsigned char _cidr);
    IPv4_coplien(const unsigned char * _adresse, const unsigned char * _masque);
    ~IPv4_coplien();//destructeur
    //Ajout pour la forme canonique en plus du destructeur
    IPv4_coplien();//constructeur par défaut
    IPv4_coplien(const IPv4_coplien& _ipv4_coplien);//opérateur d'affectation
    void ObtenirMasque(unsigned char * _masque);
    void ObtenirAdresseReseau(unsigned char * _reseau);
    void ObtenirAdresseDiffusion(unsigned char * _diffusion);
};

#endif // IPV4_COPLIEN_H
