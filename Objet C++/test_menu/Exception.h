#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <iostream>

using namespace std;

class Exception
{
public:
    Exception();
};

class ErreurIndice{
private:
    int codeErreur;
    string message;
public:
    ErreurIndice(int _codeErreur, string _message);
    int ObtenirCodeErreur() const;
    string ObtenirDescription() const;

};

class ErreurOuverture{
private:
    int codeErreur;
    string message;
public:
    ErreurOuverture(int _codeErreur, string _message);
    int ObtenirCodeErreur() const;
    string ObtenirDescription() const;

};

enum erreurs{
    INDICE=1,
    OUVERTURE
};

#endif // EXCEPTION_H
