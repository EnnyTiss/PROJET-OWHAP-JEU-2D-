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
	cout<<"Commandes : zqsd pour se déplacer, m pour quitter, i pour intéragir"<<endl;	
	cout<<"temps restant  :"<<jeu.getTimer().getValMax()-jeu.getTimer().ecoulementTimer(jeu.getTimer().getdebut())<<endl;
	cout<<"barreprog temps: "<<jeu.getBarreProg().getNow()<<endl;

	if (jeu.getTimer().getValMax()-jeu.getTimer().ecoulementTimer(jeu.getTimer().getdebut())==9 )
	{termClear();}
	
}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
	WinTXT win (40,14);//jeu.getDimX(37),jeu.getDimY(10)
	bool ok = true;
	int c;
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
				jeu.actionClavier('i');
				termClear();
				if (Etapedebut!=jeu.getEtape().getEtapenum()) {jeu.GameOver();}
				break;
			case 'm':
				ok = false;
				break;
			}
			
		} while (ok);
        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(10000);
        #endif // WIN32


	}