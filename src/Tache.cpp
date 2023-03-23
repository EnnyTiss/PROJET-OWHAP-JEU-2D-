#include "Tache.h"
#include <cassert>
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include <iostream>

using namespace std;
Tache::Tache()
{
    idTache = 0;
    difficulte = 1;
}

Tache::Tache(int diff)
{
    difficulte = diff;
}

void Tache::Combinaison(){ // saisie combinaison de touches
    
    
    string r;
    string c;
    do{
        switch (difficulte){
            case 1:
                cout<<"Appuyez sur la combinaison: Z, S"<<endl;
                r = "zs";
                break;
            case 2:
                cout<<"Appuyez sur la combinaison: Z,Q,D,S"<<endl;
                r = "zqds";break;
            case 3:
                cout<<"Appuyez sur la combinaison: S,Z,D,Q,Z,S"<<endl;
                r = "szdqzs";break;
        }
        cin >> c;
        if (c == r)
        {
            cout<<"Correct !"<<endl;
        }
        else
        {
        cout<<"Faux !"<<endl;       
        }
    }while (c!=r);
   

}

void Tache::RecopierCode(){ // saisir le code affiché à l'écran
    int r;
    srand(time(0));
    int c;
    do
    {
    switch (difficulte)
    {
    case 1:
        r = rand() % 999;break;
    case 2:
        r = rand() % 9999;break;
    case 3:
        r = rand() % 9999;break;
    }
    
        cout << "Saisir le code : " << r << endl;
        cin >> c;
        if (c == r)
        {
            cout << "Correct !" << endl;
        }
        else
        {
            cout << "Faux !" << endl;
        }
    } while (c != r);
}

void Tache::Calcul(){  // résoudre un calcul simple
    srand(time(0)); // réinitialise la génération aléatoire

    int r1;
    int r2;
    int c;
    int r;

    switch (difficulte)
    {
    case 1:
        r1 = rand() % 10;
        r2 = rand() % 10;break;
    case 2:
        r1 = rand() % 100;
        r2 = rand() % 100;break;
    case 3:
        r1 = rand() % 1000;
        r2 = rand() % 1000;break;
    }

    do
    {
        cout << "Combien vaut " << r1 << " + " << r2 << endl;
        cin >> c;
        r=r1 +r2;
        if (c == r)
        {
            cout << "Correct !" << endl;
        }
        else
        {
            cout << "Faux !" << endl;
        }
    } while (c != r1 + r2);

}
void Tache::SpamTouche(){ // appuyer sur une touche un nombre de fois
    string r;
    string c;
    do{
        switch (difficulte){
            case 1:
                cout << "Spam 5 fois g"<<endl;
                r = "ggggg";
                break;
            case 2:
                cout << "Spam 10 fois g" <<endl;
                r = "gggggggggg";
                break;
            case 3:
                cout << "Spam 15 fois g"<<endl;
                r = "ggggggggggggggg";
                break;
        }
        cin >> c;
        if (c == r)
        {
            cout << "Correcte !";
        }
        else
        {
            cout << "Faux !";
        }
    } while (c != r);
}
void Tache::Question(){ // répondre à une question
    string r;
    string c;
    do{
        switch (difficulte){
            case 1:
                cout << "Question : quelle est la réponse à la vie ? \n A: 42      B: 29      C: 12";
                r = "a";
                break;
            case 2:
                cout << "Question : quelle est la dérivée de x³ ? \n A: 3x     B: x²     C: 3x²" ;
                r = "c";
                break;
            case 3:
                cout << "Question : Le son est ... dans l'eau que dans l'air :";
                cout << "A: plus lent     B: plus rapide" ;
                r = "b";
                break;
        }
        cin >> c;
        if (c == r)
        {
            cout << "Correcte !";
        }
        else
        {
            cout << "Faux !";
        }
    } while (c != r);
}
void Tache::RecopierMot(){ // saisir le mot affiché à l'écran
string r;
string c;
 srand(time(0));
 int random = rand() % 4;
    do{
        switch (difficulte){
            case 1:
                switch (random)
                {
                    case 1:
                    cout << "Ecrire : soleil"<<endl;
                    r = "soleil"; break;
                    case 2 :
                    cout << "Ecrire : espace"<<endl;
                    r = "espace"; break;  
                    case 3:                  
                    cout << "Ecrire : lune"<<endl;
                    r = "lune"; break;
                    case 4:
                    cout << "Ecrire : mars"<<endl;
                    r = "mars"; break;
                }
                break;
            case 2:
                switch (random)
                {
                    case 1:
                    cout << "Ecrire : vortex"<<endl;
                    r = "vortex"; break;
                    case 2 :
                    cout << "Ecrire : planète"<<endl;
                    r = "planète"; break;  
                    case 3:                  
                    cout << "Ecrire : éclipse"<<endl;
                    r = "éclipse"; break;
                    case 4:
                    cout << "Ecrire : révolution"<<endl;
                    r = "révolution"; break;
                }
                break;
            case 3:
                switch (random)
                {
                    case 1:
                    cout << "Ecrire : astéroide de glace"<<endl;
                    r = "astéroide de glace"; break;
                    case 2 :
                    cout << "Ecrire : nébuleuse noir"<<endl;
                    r = "nébuleuse noir"; break;  
                    case 3:                  
                    cout << "Ecrire : monde tellurique"<<endl;
                    r = "monde tellurique"; break;
                    case 4:
                    cout << "Ecrire : rotation sidérale"<<endl;
                    r = "rotation sidérale"; break;
                }
                break;
        }
        cin >> c;
        if (c == r)
        {
            cout << "Correcte !";
        }
        else
        {
            cout << "Faux !";
        }
    } while (c != r);
}
void Tache::AppuiTouche(){
string r;
string c;
    do{
        switch (difficulte){
            case 1:
                switch (random)
                {
                    case 1:
                    cout << "Je suis l'argent au USA"<<endl;
                    r = "$"; break;
                    case 2 :
                    cout << "Je suis le symbole Modulo"<<endl;
                    r = "%"; break;  
                    case 3:                  
                    cout << "Je suis un liquide vital"<<endl;
                    r = "o"; break;
                    case 4:
                    cout << "Je suis entre le R et le T"<<endl;
                    r = "s"; break;
                }
                break;
            case 2:
                switch (random)
                {
                    case 1:
                    cout << "Je peut être des mers, filante ou à neutron"<<endl;
                    r = "*"; break;
                    case 2 :
                    cout << "Je fini chaque "<<endl;
                    r = "planète"; break;  
                    case 3:                  
                    cout << "Ecrire : éclipse"<<endl;
                    r = "éclipse"; break;
                    case 4:
                    cout << "Ecrire : révolution"<<endl;
                    r = "révolution"; break;
                }
                break;
            case 3:
                switch (random)
                {
                    case 1:
                    cout << "Ecrire : astéroide de glace"<<endl;
                    r = "astéroide de glace"; break;
                    case 2 :
                    cout << "Ecrire : nébuleuse noir"<<endl;
                    r = "nébuleuse noir"; break;  
                    case 3:                  
                    cout << "Ecrire : monde tellurique"<<endl;
                    r = "monde tellurique"; break;
                    case 4:
                    cout << "Ecrire : rotation sidérale"<<endl;
                    r = "rotation sidérale"; break;
                }
                break;
        }
        cin >> c;
        if (c == r)
        {
            cout << "Correcte !";
        }
        else
        {
            cout << "Faux !";
        }
    } while (c != r);
}

void Tache::Findevent(){
    cout<<"bien ouej"<<endl;

}

void Tache::actionTache(int idT){ // appel d'une tâche spécifique selon l'ID
switch (idT) {
					case 0 :
						RecopierCode();
						break;
					case 1 :
						AppuiTouche();
						break;
					case 2 :
						Combinaison();
						break;
					case 3 :
						Question();
						break;
					case 4 :
						SpamTouche();
						break;
					
					case 5 :
						RecopierMot();
						break;
					case 6 :
						Calcul();
						break;
					case 7 :
						Findevent();
						break;
				 }
}