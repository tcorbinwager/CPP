#include "Exception.h"

ErreurOuverture::ErreurOuverture(int _codeErreur, string _message):
    codeErreur(_codeErreur),
    message(_message)
{
}

int ErreurOuverture::ObtenirCodeErreur() const{
    return codeErreur;
}

string ErreurOuverture::ObtenirDescription() const{
    return message;
}

ErreurIndice::ErreurIndice(int _codeErreur, string _message):
    codeErreur(_codeErreur),
    message(_message)
{
}

int ErreurIndice::ObtenirCodeErreur() const{
    return codeErreur;
}

string ErreurIndice::ObtenirDescription() const{
    return message;
}

