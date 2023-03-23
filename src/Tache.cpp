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
        r = rand() % 999999;break;
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
        r2 = rand() % 100;break;
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
                cout << "Spam 5 fois '0'"<<endl;
                r = "00000";
                break;
            case 2:
                cout << "Spam 10 fois '0' " <<endl;
                r = "0000000000";
                break;
            case 3:
                cout << "Spam 15 fois '0' "<<endl;
                r = "000000000000000";
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
 srand(time(0));
 int random = rand()%4;
    do{
        switch (difficulte){
            case 1:
                switch (random)
                {
                    case 1:
                    cout << "Question : La réponse à la vie ?"<<endl;
                    cout << "a:42  b:non"<<endl;
                    r = "a"; break;
                    case 2 :
                    cout << "Question : Pourquoi ?"<<endl;
                    cout << "a:je sais pas  b:feur"<<endl;
                    r = "b"; break;  
                    case 3:                  
                    cout << "Question : La première lettre de l'alphabet ?"<<endl;
                    cout << "a:b  b:a"<<endl;                   
                    r = "b"; break;
                    case 0:
                    cout << "Question : Simple,"<<endl;
                    cout << "a:Difficile b:Basique"<<endl;
                    r = "b"; break;
                }
                break;
            case 2:
                switch (random)
                {
                    case 1:
                    cout << "Question : Quel est la dérivée de x³ ?"<<endl;
                    cout << "a:x²  b:2x³  c:3x²"<<endl;
                    r = "c"; break;
                    case 2 :
                    cout << "Question : Qui est le dieu romain de la guerre ?"<<endl;
                    cout << "a:Mars b:Ares  c:Guerroyeur le destructeur"<<endl;
                    r = "a"; break;
                    case 3:                  
                    cout << "Question : Qui a crée le courant electrique alternatif ?"<<endl;
                    cout << "a:Thomas edison  b:Nikola Tesla  c:Elon Musk  d:125"<<endl;
                    r = "c"; break;
                    case 0:
                    cout << "Question : Qui est le premier homme a avoir marché sur la lune ? "<<endl;
                    cout << "a:Buzz Aldrin  b:Neil Armstrong  c:Youri Gagarine"<<endl;
                    r = "b"; break;
                }
                break;
            case 3:
                switch (random)
                {
                    case 1:
                    cout << "Question : Le son est ... dans l'eau que dans l'air"<<endl;
                    cout << "a:Plus rapide  b:Plus lent  c:Aussi rapide  d:Aussi lent"<<endl;
                    r = "a"; break;
                    case 2 :
                    cout << "Question : La tour Eiffel à été construite en ... "<<endl;
                    cout << "a:1823  b:1889  c:1952  d:2010"<<endl;
                    r = "b"; break;
                    case 3:                  
                    cout << "Question : Une année lumière est égale à .... milliards de km"<<endl;
                    cout << "a:30  b:6667  c:9460  d:125"<<endl;
                    r = "c"; break;
                    case 0:
                    cout << "Question : la France partage sa plus grand frontière avec ... "<<endl;
                    cout << "a:l'Allemagne  b:l'Espagne  c:le Japon  d:le Brésil"<<endl;
                    r = "d"; break;
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
void Tache::RecopierMot(){ // saisir le mot affiché à l'écran
string r;
string c;
srand(time(0));
int random = rand()%4;
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
                    case 0:
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
                    case 0:
                    cout << "Ecrire : mercure"<<endl;
                    r = "mercure"; break;
                }
                break;
            case 3:
                switch (random)
                {
                    case 1:
                    cout << "Ecrire : astéroide"<<endl;
                    r = "astéroide"; break;
                    case 2 :
                    cout << "Ecrire : nébuleuse"<<endl;
                    r = "nébuleuse"; break;  
                    case 3:                  
                    cout << "Ecrire :tellurique"<<endl;
                    r = "tellurique"; break;
                    case 0:
                    cout << "Ecrire :sidérale"<<endl;
                    r = "sidérale"; break;
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
srand(time(0));
int random = rand() % 4;
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
                    case 0:
                    cout << "Je suis entre le R et le T dans l'alphabet"<<endl;
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
                    cout << "Je vous fait un clin d'oeil en souriant"<<endl;
                    r = ";)"; break;  
                    case 3:                  
                    cout << "Je suis bu par les anglais"<<endl;
                    r = "t"; break;
                    case 0:
                    cout << "Je suis beaucoup de rire"<<endl;
                    r = "lol"; break;
                }
                break;
            case 3:
                switch (random)
                {
                    case 1:
                    cout << "Je peut être l'infini si on me tourne ou le vide si on me coupe"<<endl;
                    r = "8"; break;
                    case 2 :
                    cout << "Je vais de haut en bas"<<endl;
                    r = "↓"; break;  
                    case 3:                  
                    cout << "Je suis le o et le e "<<endl;
                    r = "œ"; break;
                    case 0:
                    cout << "Je sert à couper des arbres"<<endl;
                    r = "h"; break;
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
						Calcul();
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
						Combinaison();
						break;
					case 7 :
						Findevent();
						break;
				 }
}