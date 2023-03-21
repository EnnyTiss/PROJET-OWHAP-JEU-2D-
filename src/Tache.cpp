#include "Tache.h"
#include <cassert>
#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>

using namespace std;

Tache::Tache()
{
    idTache = 0;
    difficulte = 1;
}

Tache::Tache(int idT, int diff)
{
    idTache = idT;
    difficulte = diff;
}

void Tache::Combinaison(){ // saisie combinaison de touches
    string r;
    string c;
    do{
        switch (difficulte){
            case 1:
                cout << "Appuyez sur la combinaison: Z, S"<<endl;
                r = "ZS";
            case 2:
                cout << "Appuyez sur la combinaison: Z, Q, D, S"<<endl;
                r = "ZQDS";
            case 3:
                cout << "Appuyez sur la combinaison: S, Z, D, Q, Z, S"<<endl;
                r = "SZDQZS";
        }
        cin >> c;
        if (c == r)
        {
            cout << "Combinaison correcte !" << endl;
        }
        else
        {
            cout << "Combinaison erronée!" << endl;
        }
    }while (c!=r);


}

void Tache::RecopierCode(){ // saisir le code affiché à l'écran
    int r;
    int c;

    switch (difficulte)
    {
    case 1:
        r = 234;
    case 2:
        r = 4254;
    case 3:
        r = 19360;
    }
    do
    {
        cout << "Saisir le code : " << r << endl;
        cin >> c;
        if (c == r)
        {
            cout << "Code correct !" << endl;
        }
        else
        {
            cout << "Code erroné!" << endl;
        }
    } while (c != r);
}

void Tache::Calcul(){  // résoudre un calcul simple
    srand(time(0)); // réinitialise la génération aléatoire

    int r1;
    int r2;
    int c;

    switch (difficulte)
    {
    case 1:
        r1 = rand() % 10;
        r2 = rand() % 10;
    case 2:
        r1 = rand() % 100;
        r2 = rand() % 100;
    case 3:
        r1 = rand() % 1000;
        r2 = rand() % 1000;
    }

    do
    {
        cout << "Combien vaut" << r1 << " + " << r2 << endl;
        cin >> c;
    } while (c != r1 + r2);
}
void Tache::SpamTouche(){ // appuyer sur une touche un nombre de fois

}
void Tache::Question(){ // répondre à une question
    string r;
    string c;
    do{
        switch (difficulte){
            case 1:
                cout << "Question : quelle est la réponse à la vie ? \n A: 42      B: 29      C: 12"<< endl;
                r = "A";
                break;
            case 2:
                cout << "Question : quelle est la dérivée de x³ ? \n A: 3x     B: x²     C: 3x²" << endl;
                r = "C";
                break;
            case 3:
                cout << "Question : Le son est ... dans l'eau que dans l'air :"<<endl;
                cout << "A: plus lent     B: plus rapide" <<endl;
                r = "B";
                break;
        }
        cin >> c;
        if (c == r)
        {
            cout << "Réponse correcte !" << endl;
        }
        else
        {
            cout << "Réponse fausse !" << endl;
        }
    } while (c != r);
}
void Tache::RecopierMot(){ // saisir le mot affiché à l'écran

}
void Tache::AppuiTouche(){

}

void Tache::actionTache(int idT){ // appel d'une tâche spécifique selon l'ID

}