#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxtO.h"
#include <iostream>
using namespace std;
#include "Vaisseau.h"

void txtAff(WinTXT & win, const Vaisseau & jeu) {


	win.clear();

    // Affichage des murs et des pastilles
	for(int x=0;x<jeu.getDimX();++x)
		{for(int y=0;y<jeu.getDimY();++y)
			{win.print( y, x, jeu.getXY(x,y));
	
			}
			
		}
		/*for (int i=0; i<jeu.getDimX(); i++)
    	{
        for (int j=0; j<jeu.getDimY(); j++)
        {
            cout<<jeu.getXY(i,j);
        }
        cout<<endl;
    	}*/

	win.draw();
}

void txtBoucle (Vaisseau & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (37,10);//jeu.getDimX(),jeu.getDimY()
	

	do {
	    txtAff(win,jeu);
		if  (win.getCh()=='m')
			{break;}
        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(10000);
        #endif // WIN32


	} while (true);

}