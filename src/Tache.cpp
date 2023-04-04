#include "Tache.h"



using namespace std;
Tache::Tache()
{
    idTache = 0;
    difficulte = 1;
    string resString=".";
    string quesString=".";

}

Tache::Tache(int diff)
{
    difficulte = diff;
}

void Tache::Combinaison(){ // saisie combinaison de touches
    
    srand(time(0));
    int f1=rand() %4;
     srand(time(0)+9);
    int f2=rand() %4;
     srand(time(0)+5);
    int f3=rand() %4;
     srand(time(0)+111);
    int f4=rand() %4;
    string f1c;
    switch (f1){
        case 1: f1c="z";break;
        case 2: f1c="s";break;
        case 3: f1c="q";break;
        case 0: f1c="d";break;
        default:break;
    }
    string f2c;
    switch (f2){
        case 1: f2c="z";break;
        case 2: f2c="s";break;
        case 3: f2c="q";break;
        case 0: f2c="d";break;
        default:break;
    }
    string f3c;
    switch (f3){
        case 1: f3c="z";break;
        case 2: f3c="s";break;
        case 3: f3c="q";break;
        case 0: f3c="d";break;
        default:break;
    }
    string f4c;
    switch (f4){
        case 1: f4c="z";break;
        case 2: f4c="s";break;
        case 3: f4c="q";break;
        case 0: f4c="d";break;
        default:break;
    }
            switch (difficulte){
            case 1:
                resString = f1c+f2c;
                break;
            case 2:
                resString = f1c+f2c+f3c+f4c;break;
            case 3:
                resString =f4c+f1c+f2c+f3c+f4c+f1c;break;
            default:break;
        }
            quesString=" Appuyez sur la combinaison:"+resString;

}

void Tache::RecopierCode(){ // saisir le code affiché à l'écran
    srand(time(0));
    int r; 

    switch (difficulte)
    {
    case 1:
        r = rand() % 999;break;
    case 2:
        r = rand() % 9999;break;
    case 3:
        r = rand() % 999999;break;
    default:break;
    }
    
        quesString="Saisir le code : "+to_string(r);
        resString =to_string(r);

}

void Tache::Calcul(){  // résoudre un calcul simple
    srand(time(0)); // réinitialise la génération aléatoire
        int c; 
        int r1;
        int r2;


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
    default:break;
    }
     string sr1=to_string(r1);     string sr2=to_string(r2);
     quesString="Combien vaut "+sr1+"+"+sr2;
     c=r1+r2;
     resString=to_string(c);

}
void Tache::SpamTouche(){ // appuyer sur une touche un nombre de fois
        switch (difficulte){
            case 1:
                quesString="Spam 5 fois 0 ";
                resString ="00000";

                break;
            case 2:
                quesString="Spam 10 fois 0 ";
                 resString ="0000000000";
                break;
            case 3:
                quesString="Spam 15 fois 0 ";
                resString ="000000000000000";
                break;
            default:break;
        }

}
void Tache::Question(){ // répondre à une question
 srand(time(0));
 int random = rand()%4;
        switch (difficulte){
            case 1:
                switch (random)
                {
                    case 1:
                    quesString="La réponse à la vie ?  a:42  b:non";
                    resString = "a"; break;
                    case 2 :
                    quesString="Pourquoi ? a:je sais pas  b:feur";
                    resString = "b"; break;  
                    case 3:                  
                    quesString="La première lettre de l'alphabet ?  a:b  b:a";                  
                    resString = "b"; break;
                    case 0:
                    quesString="Simple, ... ? a:Difficile b:Basique";
                    resString = "b"; break;
                    default:break;
                }
                break;
            case 2:
                switch (random)
                {
                    case 1:
                    quesString=" Quel est la dérivée de x³ ? a:x²  b:2x³  c:3x²";
                    resString = "c"; break;
                    case 2 :
                    quesString=" Qui est le dieu romain de la guerre ? a:Mars b:Ares  c:Guerroyeur le destructeur";
                    resString = "a"; break;
                    case 3:                  
                    quesString=" Qui a crée le courant electrique alternatif ? a:Thomas edison  b:Nikola Tesla  c:Elon Musk  d:125";
                    resString = "c"; break;
                    case 0:
                    quesString=" Qui est le premier homme a avoir marché sur la lune ? a:Buzz Aldrin  b:Neil Armstrong  c:Youri Gagarine";
                    resString = "b"; break;
                    default:break;
                }
                break;
            case 3:
                switch (random)
                {
                    case 1:
                    quesString=" Le son est ... dans l'eau que dans l'air a:Plus rapide  b:Plus lent  c:Aussi rapide  d:Aussi lent";
                    resString = "a"; break;
                    case 2 :
                    quesString=" La tour Eiffel à été construite en ... a:1823  b:1889  c:1952  d:2010";
                    resString = "b"; break;
                    case 3:                  
                    quesString=" Une année lumière est égale à ... milliards de km   a:30  b:6667  c:9460  d:125";
                    resString = "c"; break;
                    case 0:
                    quesString=" la France partage sa plus grand frontière avec ... a:l'Allemagne  b:l'Espagne  c:le Japon  d:le Brésil";
                    resString = "d"; break;
                    default:break;
                }
                break;
            default:break;
}}


void Tache::RecopierMot(){ // saisir le mot affiché à l'écran

srand(time(0));
int random = rand()%4;
        switch (difficulte){
            case 1:
                switch (random)
                {
                    case 1:
                    quesString="Ecrire : soleil";
                    resString = "soleil"; break;
                    case 2 :
                    quesString= "Ecrire : espace";
                    resString = "espace"; break;  
                    case 3:                  
                    quesString= "Ecrire : lune";
                    resString = "lune"; break;
                    case 0:
                    quesString="Ecrire : mars";
                    resString = "mars"; break;
                    default:break;
                }
                break;
            case 2:
                switch (random)
                {
                    case 1:
                    quesString= "Ecrire : vortex";
                    resString = "vortex"; break;
                    case 2 :
                    quesString="Ecrire : planète";
                    resString = "planète"; break;  
                    case 3:                  
                    quesString= "Ecrire : éclipse";
                    resString = "éclipse"; break;
                    case 0:
                    quesString= "Ecrire : mercure";
                    resString = "mercure"; break;
                    default:break;
                }
                break;
            case 3:
                switch (random)
                {
                    case 1:
                    quesString= "Ecrire : astéroide";
                    resString = "astéroide"; break;
                    case 2 :
                    quesString= "Ecrire : nébuleuse";
                    resString = "nébuleuse"; break;  
                    case 3:                  
                    quesString="Ecrire : tellurique";
                    resString = "tellurique"; break;
                    case 0:
                    quesString= "Ecrire : sidérale";
                    resString = "sidérale"; break;
                    default:break;
                }
                break;
            default:break;
        }


}
void Tache::AppuiTouche(){
string r;
string c;
srand(time(0));
int random = rand() % 4;
        switch (difficulte){
            case 1:
                switch (random)
                {
                    case 1:
                    quesString="Je suis l'argent au USA";
                    resString = "$"; break;
                    case 2 :
                    quesString= "Je suis le symbole Modulo";
                    resString = "%"; break;  
                    case 3:                  
                    quesString= "Je suis un liquide vital";
                    resString = "o"; break;
                    case 0:
                    quesString= "Je suis entre le R et le T dans l'alphabet";
                    resString = "s"; break;
                    default:break;
                }
                break;
            case 2:
                switch (random)
                {
                    case 1:
                    quesString=  "Je peut être des mers, filante ou à neutron";
                    resString = "*"; break;
                    case 2 :
                    quesString=  "Je vous fait un clin d'oeil en souriant";
                    resString = ";)"; break;  
                    case 3:                  
                    quesString=  "Je suis bu par les anglais";
                    resString = "t"; break;
                    case 0:
                    quesString=  "Je sert à couper des arbres";
                    resString = "h"; break;
                    default:break;
                }
                break;
            case 3:
                switch (random)
                {
                    case 1:
                     quesString= "Je peut être l'infini si on me tourne ou le vide si on me coupe";
                    resString = "8"; break;
                    case 2 :
                     quesString= "Je vais de haut en bas";
                    resString = "↓"; break;  
                    case 3:                  
                     quesString= "Je suis le o et le e ";
                    resString = "œ"; break;
                    case 0:
                     quesString= "Je suis un a dans un o";
                    resString = "@"; break;
                    default:break;
                }
                break;
            default:break;
        }

}

void Tache::Findevent(){
quesString= "0";
resString = "0";
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
                    default:break;
				 }
}