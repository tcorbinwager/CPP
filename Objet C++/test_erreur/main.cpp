#include <iostream>

using namespace std;

int main()
{

    int nombre1, nombre2;
    float resultat;
    try {

        cout << "Entrez deux nombres entiers :";
        cin >> nombre1 >> nombre2;
        if(nombre2 == 0){
            throw string("Erreur de division par ZERO !");
        }else{
            resultat = nombre1 / static_cast<float>(nombre2); //convertion d'un int en float
            cout << resultat << endl;

        }

    } catch (string const chaine) {
     cerr << chaine << endl;
    }

    return 0;
}
