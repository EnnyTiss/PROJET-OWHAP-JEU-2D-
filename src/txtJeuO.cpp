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
	//cout<<endl<<"position perso :"<<jeu.getPerso().getPosPerso().x<<" "<<jeu.getPerso().getPosPerso().y<<endl;
	if (jeu.getTimer().ecoulementTimer()<=jeu.getTimer().getValMax()/1000)
	{cout<<"temps restant  :"<<jeu.getTimer().getValMax()/1000-jeu.getTimer().ecoulementTimer()<<endl;
	cout<<"barreprog temps: "<<jeu.getBarreProg().getNow()<<endl;}
	else{jeu.getTimer().GameOver(); }
	
	//if (jeu.getEtape().estEtape(jeu.getTimer())) {cout<<"c'est une étape";}
	//else cout<<"c'est non étape";
	
}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT ecran (100,100); ecran.clear(); ecran.draw(); // pour clear l'écran
	WinTXT win (70,14);//jeu.getDimX(37),jeu.getDimY(10)
	bool ok = true;
	int c;
	do {
	    txtAff(win,jeu);
		jeu.NouvelleEtape();
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
				jeu.actionClavier('i');
				termClear();
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