#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxtO.h"
#include "Jeu.h"

using namespace std;

void txtAff(WinTXT & win, const Jeu & jeu) {


	win.clear();
	
	

    // Affichage du décors, du perso et des évenements
	for(int x=0;x<jeu.getVaisseau().getDimX();++x){
		for(int y=0;y<jeu.getVaisseau().getDimY();++y)
			{
				if (Vec2D(x,y)==jeu.getPerso().getPosPerso())
				{win.print (y,x, 'P');}
				else 
				{
					win.print( y, x, jeu.getVaisseau().getXY(x,y));
					for (int i=0; i<8; i++)
					{
					if (Vec2D(x,y)==jeu.getObjet(i).getPosObjet() && jeu.getObjet(i).getActifObjet())
					{win.print (y,x, '!');}
					//else {win.print (y,x, jeu.getVaisseau().getXY(x,y));}
					} 
				}
				
			}
			
			
	}
	//Affichage de la barre de prog
	for (int i=0; i<jeu.getBarreProg().getTaille();i++)
				{ if (i==jeu.getBarreProg().getNow())
				  {
					  if (jeu.getBarreProg().getC(i)=='0')
					  {win.print(i,10,'8');}
					  else
					  {win.print(i,10,'X');}}
				  else
					{win.print(i,10, jeu.getBarreProg().getC(i));}
				}
	

	win.draw();
	cout<<endl<<"Commandes : zqsd pour se déplacer, m pour quitter, i pour intéragir"<<endl;	
	cout<<"temps restant  :"<<jeu.getTimer().getValMax()-jeu.getTimer().ecoulementTimer(jeu.getTimer().getdebut())<<endl;
	cout<<"barreprog temps: "<<jeu.getBarreProg().getNow()<<endl;

	if (jeu.getTimer().getValMax()-jeu.getTimer().ecoulementTimer(jeu.getTimer().getdebut())==9 )
	{termClear();}
	
}

void tacheafaire(Jeu & jeu)
{
	string c="";
	string question="";
	string res="";
	jeu.actionClavier('i');
	
	
	


	
	switch (jeu.getEtape().getEtapenum()) {
		case 1 : res=jeu.getTachefacile().getResString(); question= jeu.getTachefacile().getQuesString();break;
		case 2 : res=jeu.getTachemoyen().getResString();question= jeu.getTachemoyen().getQuesString();break;
		case 3 : res=jeu.getTachedifficile().getResString();question= jeu.getTachedifficile().getQuesString();break;
		default : break;
	}

	cout<<question;
	do {
	cin>>c;
	cout<<"/"<<res<<"/";

	//if (c!=res)
	//cout<<"Faux !";
	}while (c!=res);
}

void recommencer(Jeu& j)
{
j.getTimer().reinitialiser();
j.getPerso().setPosPerso(5,16);
j.getEtape().getTimerEtape().reinitialiser();
j.getBarreProg().getTimerBR().reinitialiser();

}



void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
	WinTXT win (40,14);//jeu.getDimX(37),jeu.getDimY(10)
	bool ok = true;
	int c;
	char var='m';
	Timer tmp;
	do {
	    txtAff(win,jeu);
		
		jeu.NouvelleEtape();
		
		
		 int Etapedebut = jeu.getEtape().getEtapenum();

		c=win.getCh();
		switch (c) {
			case 'z':
				jeu.actionClavier('z');
				break;
			case 's':
				jeu.actionClavier('s');
				break;
			case 'q':
				jeu.actionClavier('q');
				break;
			case 'd':
				jeu.actionClavier('d');
				break;
			case 'i':
				termClear();
				tacheafaire(jeu);
				termClear();
				if (Etapedebut!=jeu.getEtape().getEtapenum()) {jeu.GameOver();}
				break;
			case 'm':
				termClear();
				cout<<"Menu Pause"<<endl<<endl;
				cout<<"r -> Reprendre"<<endl<<"y-> Recommencer"<<endl<<"q -> Quitter";
				
				tmp=Timer(); tmp=Timer(60, 0, 666, true);
				do { 
				cin>>var;
				if (var=='q') {ok=false;termClear();}
				if (var=='r') {jeu.getTimer().setDecalage(-tmp.ecoulementTimer(tmp.getdebut()));}
				if (var=='y') { recommencer(jeu);}
				} while(var!='r' && var!='q' && var!='y');
				break;
			case 'n': ok=false;  break;
			}
			
		} while (ok);
        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(10000);
        #endif // WIN32


	}

