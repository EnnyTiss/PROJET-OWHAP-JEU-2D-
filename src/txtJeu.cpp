#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"

#include "JeuOWHAP.h"

void txtAff(WinTXT & win, const JeuOWHAP & Jeu) {
	const Vaisseau& ter = Jeu.getConstVaisseau();


	win.clear();

    // Affichage des murs et des pastilles
	for(int x=0;x<ter.getDimX();++x)
		for(int y=0;y<ter.getDimY();++y)
			win.print( x, y, ter.getXYasChar(x,y));


	win.draw();
}

void txtBoucle (JeuOWHAP & Jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (Jeu.getConstVaisseau().getDimX(),Jeu.getConstVaisseau().getDimY());

	bool ok = true;
	int c;

	do {
	    txtAff(win,Jeu);

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32

	} while (ok);

}
