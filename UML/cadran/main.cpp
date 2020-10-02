#include <iostream>
#include "cadran.h"


using namespace std;

int main()
{
    //Cadran leCadran;
    Cadran unAutreCadran(10, 10, 2, 20,ROUGE,CYANP);
    string fin="Fin";
    int test=10;

    /*for(int i=0;i<11;i++){
        unAutreCadran.Afficher(i,3,2);
        sleep(1);
    }
    unAutreCadran.Effacer();
    unAutreCadran.Afficher(fin,1,2);*/


        for (int i=0;i<11;i++){

            unAutreCadran.Afficher(test,5,2);
            test -= 1;
            sleep(1);

            if(i==10){
                unAutreCadran.Effacer();
                unAutreCadran.Afficher(fin,1,1);
            }
        }


    return 0;
}
