#include <iostream>

using namespace std;

int main()
{
    int Valeurs[5]{5,7,2,1,4};
    int i;
    int t;
    int z;
    int stock1;

    for(z=0;z<5;z++){
    cout << Valeurs[z] << " | ";
    }
    cout << endl;
    cout << endl;
    cout << endl;

    for(t=0;t<4;t++){
    stock1=Valeurs[t];

    for(i=t;i<5;i++){

        if(Valeurs[i]<stock1){
            Valeurs[t]=Valeurs[i];
            Valeurs[i]=stock1;
            stock1=Valeurs[t];
        }

    }

    for(z=0;z<5;z++){
    cout << Valeurs[z] << " | ";
    }
    cout << endl;

    }


    return 0;
}
