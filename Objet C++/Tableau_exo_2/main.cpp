#include <iostream>

using namespace std;

int main()
{
    int Valeurs[8];
    int stock1;
    int stock2;
    int i;
    int t=0;

    cout << "Les 8 valeurs : " << endl;

    for(i=0; i<8 ; i++){

    cin >> Valeurs[i];
    }
    cout <<endl;
    cout <<endl;

    for(i=0;i<8;i++){
        cout << Valeurs[i]<<" | ";

    }
    cout <<endl;

    while(t<8){

    for(i=0; i<8;i++){

        if(i==0){
            stock1 = Valeurs[i+1];
            Valeurs[i+1]=Valeurs[i];
        }
        if(i==1 || i==3 ||i==5){
            stock2 =Valeurs[i+1];
            Valeurs[i+1]=stock1;
        }
        if(i==2 || i==4 || i==6){
            stock1 = Valeurs[i+1];
            Valeurs[i+1]=stock2;
        }
        if(i==7){
            Valeurs[0]=stock1;
        }


    }

    for(i=0;i<8;i++){
        cout << Valeurs[i] << " | ";
    }
    cout <<endl;

    t++;
    }


    return 0;
}
