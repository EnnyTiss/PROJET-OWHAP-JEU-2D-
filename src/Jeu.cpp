#include "Jeu.h"
#include <iostream>
using namespace std;

Jeu::Jeu() 
{
	v=Vaisseau(); 
	p=Perso();
	tabo[0]= Objet(); tabo[0].setObjet(0,true,1,1);
	tabo[1]= Objet();tabo[1].setObjet(1,false,8,1); 
	tabo[2]= Objet();tabo[2].setObjet(2,false,8,11);
	tabo[3]= Objet();tabo[3].setObjet(3,false,1,11); 
	tabo[4]= Objet();tabo[4].setObjet(4,false,1,28);
	tabo[5]= Objet();tabo[5].setObjet(5,false,8,28); 
	tabo[6]= Objet();tabo[6].setObjet(6,false,5,34);
	tabo[7]= Objet();tabo[7].setObjet(7,false,4,16); 
	timer= Timer(); timer=Timer(60,0,18000,true);
	BP=BarreProg();

	timer = Timer(); timer=Timer(60,0,60,true);


}

//const Vaisseau& Jeu::getVaisseau () const{ return v; }

//const Perso& Jeu::getPerso () const{	return p; }

bool Jeu::PersoPresDeObjet(){
	
	int xP = getPerso().getPosPerso().x;
	int yP = getPerso().getPosPerso().y;

	for (int i=xP-1; i<xP+2; i++){
		for (int j=yP-1; j<yP+2; j++){
			assert(getVaisseau().getXY(i,j)!= 'P');
			if (getVaisseau().getXY(i,j)!='.' && getVaisseau().getXY(i,j)!='!' && getVaisseau().getXY(i,j) != '#' && getVaisseau().getXY(i,j) != ' '){
				return true;
				break;
			}
			
		}
	}  return false;
}

void Jeu::interationdemande(){
	if (PersoPresDeObjet())
	{
		cout<<"y a un obj "<<endl;

		int b;
		int a;
		int xP = getPerso().getPosPerso().x;
		int yP = getPerso().getPosPerso().y;

		for (int i=xP-1; i<xP+2; i++){
			for (int j=yP-1; j<yP+2; j++){
				assert(getVaisseau().getXY(i,j)!= 'P');
				if (getVaisseau().getXY(i,j)!='.' && getVaisseau().getXY(i,j)!='!' && getVaisseau().getXY(i,j) != '#' && getVaisseau().getXY(i,j) != ' '){
				 a=i;
				 b=j;
				 int num = (int) getVaisseau().getXY(i,j);
				 num=num-'0';
				 
				 cout<<a<<" "<<b<<"    "<<num<<" "<<endl;
				 getObjet(num).setActifObjet(false);
				}
			
			}
	}
	} else cout<<"ya r        "<<endl;
}


bool Jeu::actionClavier (const char touche) {
	switch(touche) {
		case 'q' :
				p.gauche(v);
				break;
		case 'd' :
				p.droite(v);
				break;
		case 'z' :
				p.haut(v);
				break;
		case 's' :
				p.bas(v);
				break;
		case 'i' :
				interationdemande();
				break;
	}
	

	return false;
}



