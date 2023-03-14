#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxtO.h"
#include <iostream>
using namespace std;
#include "Jeu.h"

void txtAff(WinTXT & win, const Jeu & jeu) {


	win.clear();
	

    // Affichage des murs et des pastilles
	for(int x=0;x<jeu.getVaisseau().getDimX();++x)
		{for(int y=0;y<jeu.getVaisseau().getDimY();++y)
			{
				if (x==jeu.getPerso().getX() && y==jeu.getPerso().getY())
				{win.print (y,x, 'P');}
				else win.print( y, x, jeu.getVaisseau().getXY(x,y));;
			}
			
			
		}

	win.draw();
	cout<<endl<<"Commandes : zqsd pour se dépalcer, m pour quitter, i pour intéragir"<<endl;
	cout<<endl<<"position perso :"<<jeu.getPerso().getX()<<" "<<jeu.getPerso().getY()<<"   "<<endl;

}

void txtBoucle (Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT ecran (100,100); ecran.clear(); ecran.draw(); // pour clear l'écran
	WinTXT win (37,10);//jeu.getDimX(37),jeu.getDimY(10)
	bool ok = true;
	int c;
	do {
	    txtAff(win,jeu);
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