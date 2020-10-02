#include <iostream>

#define NBELEVES 5

using namespace std;

int main()
{

    float Notes[NBELEVES];
    int i=0;
    float mini=10;
    float max=10;
    float somme=0;
    float Moyenne=5;
    int NoteSup=0;

        cout << "Les notes des élèves : " << endl;

        for(i=0; i<NBELEVES ; i++){

        cin >> Notes[i];

        if(mini>Notes[i]){
            mini=Notes[i];
        }

        if(max<Notes[i]){
            max=Notes[i];
        }

        if(Notes[i]>=10){
            NoteSup++;
        }

        somme = somme + Notes[i];

        }

        for(i=0; i<NBELEVES ; i++){
            cout << "L'élève numèro " << i+1 << " a eu la note de " << Notes[i] << " / 20 " <<endl;
        }

        Moyenne = somme / NBELEVES ;

        cout << "La note minimale est : " << mini << " / 20" <<endl;
        cout << "La note maximale est : " << max << " / 20" << endl;
        cout << "La moyenne des notes est : " << Moyenne << " / 20 "<< endl;
        cout << "Il y a eu " << NoteSup << " note(s) ayant eu 10 ou plus" << endl;

    return 0;
}
