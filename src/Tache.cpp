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
        cout << "Combien vaut" << r1 << " + " << r2 << endl;
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
    do{
        switch (difficulte){
            case 1:
                cout << "Ecrire le mot arbre"<<endl;
                r = "arbre";
                break;
            case 2:
                cout << "Ecrire le mot révolution" <<endl;
                r = "révolution";
                break;
            case 3:
                cout << "Ecrire le mot anticonformiste"<<endl;
                r = "anticonformiste";
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
                cout << "Trouver la touche qui représente l'argent"<<endl;
                r = "$";
                break;
            case 2:
                cout << "Trouver la touche qui représente l'infini de coté" <<endl;
                r = "8";
                break;
            case 3:
                cout << "Trouver la touche qui représente modulo"<<endl;
                r = "%";
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
						Question();
						break;
					case 1 :
						Combinaison();
						break;
					case 2 :
						RecopierCode();
						break;
					case 3 :
						Calcul();
						break;
					case 4 :
						SpamTouche();
						break;
					
					case 5 :
						RecopierMot();
						break;
					case 6 :
						AppuiTouche();
						break;
					case 7 :
						Findevent();
						break;
				 }
}