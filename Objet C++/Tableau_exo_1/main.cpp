#include <iostream>   //Pour count

using namespace std;  //Evite d'écrire std:cout

int main()
{
    cout << "Bienvenue en C++" << endl; //idem au printf

    float temperature;
    float humidite;
    int pression;

    cout << "Saisir la température, l'humidité et la pression : " ;
    cin >> temperature >> humidite >> pression ;

    cout << "La température est : " << temperature << "°" <<endl;
    cout << "Le taux d'humidité est : " << humidite << "%" <<endl;
    cout <<"La pression est : " << pression << "hPa" << endl;


    return 0;
}
