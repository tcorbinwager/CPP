#include "Menu.h"
#include "Exception.h"


Menu::Menu(const string &_nom):nom(_nom), longueurMax(0){

    fstream fichierMenu(nom.c_str(), fstream::in | fstream::out);
    if(!fichierMenu.is_open()){
        ErreurOuverture excep(OUVERTURE,"Erreur lors de l'ouverture du fichier");
        throw(excep);
        nbOptions = 0;
    }else{
        nbOptions=static_cast<int>(count(istreambuf_iterator<char>(fichierMenu),istreambuf_iterator<char>(),'\n'));
        fichierMenu.seekg(0,ios::beg);
        if(nbOptions<=0){
            ErreurIndice excepi(INDICE,"Le tableau à un indice négatif ou est égal à 0");
            throw(excepi);
        }else
            options= new string[nbOptions];

        for(int i=0;i<nbOptions;i++){
            getline(fichierMenu, options[i]);
            int longueur = static_cast<int>(options[i].length());
            if(longueur > longueurMax){
                longueurMax = longueur;
            }
        }

    }

}

Menu::~Menu(){
    if(options != nullptr)
        delete [] options;
}

int Menu::Afficher(){
    int choix=0;
    cout << "+" << setfill('-') << setw(6) << "+" << setfill('-') <<setw(longueurMax+2) << "+" << endl;
    for(int i=0;i<nbOptions;i++){
        cout << "|" <<setfill(' ') << setw(5) << i+1 << "|" <<setw(longueurMax+1) << options[i] << "|" << endl;
    }
    cout << "+" << setfill('-') << setw(6) << "+" << setfill('-') <<setw(longueurMax+2) << "+"<< endl;

    cout <<endl;
    cout <<endl;
    cout <<endl;
    cout <<endl;
    if(choix<1 || choix > longueurMax){
        cout <<"Entrer un nombre entre 1 et 5 : ";
        cin >> choix;
    }

    if(choix<1 || choix > longueurMax){
        ErreurIndice excepti(INDICE,"Le nombre choisi n'est pas entre 1 et 5");
        throw(excepti);
    }

    return choix;

    if(!(cin>>choix)){
        cin.clear();
        cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
        choix=-1;
    }

}

void Menu::AttendreAppuiTouche(){
    string uneChaine;
    cout << endl << "appuyer sur la touche Entrée pour continuer ...";
    getline(cin,uneChaine);
    cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
    system("clear");
}




