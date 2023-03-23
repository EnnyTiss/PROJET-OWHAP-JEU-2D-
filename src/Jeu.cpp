#include "Jeu.h"
#include <iostream>
#include <unistd.h>
using namespace std;

Jeu::Jeu() 
{
	v=Vaisseau(); 
	p=Perso();
	tabo[0]= Objet();tabo[0].setObjet(0,false,1,1);
	tabo[1]= Objet();tabo[1].setObjet(1,false,8,1); 
	tabo[2]= Objet();tabo[2].setObjet(2,false,8,10);
	tabo[3]= Objet();tabo[3].setObjet(3,false,1,11); 
	tabo[4]= Objet();tabo[4].setObjet(4,false,1,28);
	tabo[5]= Objet();tabo[5].setObjet(5,false,8,28); 
	tabo[6]= Objet();tabo[6].setObjet(6,false,5,34);
	tabo[7]= Objet();tabo[7].setObjet(7,false,4,16); 
	timer= Timer(); timer=Timer(60,0,60,true);
	BP=BarreProg(60);
	E=Etape(60);
	tfacile=Tache(1);
	tmoyen=Tache(2);
	tdifficile=Tache(3);




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


		int xP = getPerso().getPosPerso().x;
		int yP = getPerso().getPosPerso().y;

		for (int i=xP-1; i<xP+2; i++){
			for (int j=yP-1; j<yP+2; j++){
				assert(getVaisseau().getXY(i,j)!= 'P');
				if (getVaisseau().getXY(i,j)!='.' && getVaisseau().getXY(i,j)!='!' && getVaisseau().getXY(i,j) != '#' && getVaisseau().getXY(i,j) != ' '){

				 int num = (int) getVaisseau().getXY(i,j);
				 num=num-'0';
				 

				 switch (E.getEtape()){
			
				 case 1 : getTachefacile().actionTache(num); break; 
				 case 2 : getTachemoyen().actionTache(num); break; 
				 case 3 : getTachedifficile().actionTache(num);break;}
				 getObjet(num).setActifObjet(false);
				 
				}
			
			}
	}
	} 
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


void Jeu::NouvelleEtape() //vérfie en boucle si une nouvelle étape doit se lancer
{
	if (getTimer().ecoulementTimer(getTimer().getdebut())==1)
	{

		switch(E.getEvenement(1).getIdEvent()) {
			case 1 : getObjet(4).setActifObjet(true); getObjet(5).setActifObjet(true); getObjet(7).setActifObjet(true); break; 
			//attaque de pirate !
			case 2 : getObjet(0).setActifObjet(true); getObjet(1).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//problème moteur !
			case 3 : getObjet(2).setActifObjet(true); getObjet(1).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//moteur sans energie !
			case 4 : getObjet(5).setActifObjet(true); getObjet(0).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//Super Nova ! fuir !
			case 5 : getObjet(5).setActifObjet(true); getObjet(6).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//champ d'astéroide !
			case 6 : getObjet(3).setActifObjet(true); getObjet(2).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//Humain sans energie !
			case 7 : getObjet(2).setActifObjet(true); getObjet(4).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//armes sans energie !
			case 8 : getObjet(2).setActifObjet(true); getObjet(5).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//bouclier sans energie !
			case 9 : getObjet(3).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//problème pour les humains !
			case 0 : getObjet(6).setActifObjet(true);  getObjet(7).setActifObjet(true);break; 
			//esquive !


		}

	}
	
	if (getTimer().ecoulementTimer(getTimer().getdebut())==getTimer().getValMax()*1/3)
	{
		
		if (toutfini()) {
		sleep(1);
		switch(E.getEvenement(2).getIdEvent()) {
			case 1 : getObjet(4).setActifObjet(true); getObjet(5).setActifObjet(true); getObjet(7).setActifObjet(true); break; 
			//attaque de pirate !
			case 2 : getObjet(0).setActifObjet(true); getObjet(1).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//problème moteur !
			case 3 : getObjet(2).setActifObjet(true); getObjet(1).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//moteur sans energie !
			case 4 : getObjet(5).setActifObjet(true); getObjet(0).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//Super Nova ! fuir !
			case 5 : getObjet(5).setActifObjet(true); getObjet(6).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//champ d'astéroide !
			case 6 : getObjet(3).setActifObjet(true); getObjet(2).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//Humain sans energie !
			case 7 : getObjet(2).setActifObjet(true); getObjet(4).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//armes sans energie !
			case 8 : getObjet(2).setActifObjet(true); getObjet(5).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//bouclier sans energie !
			case 9 : getObjet(3).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//problème pour les humains !
			case 0 : getObjet(6).setActifObjet(true);  getObjet(7).setActifObjet(true);break; 
			//esquive !
		}
		}
		else  {GameOver();}
	}

	if (getTimer().ecoulementTimer(getTimer().getdebut())==getTimer().getValMax()*2/3)
	{
		if (toutfini()) { 			
		sleep(1);
		switch(E.getEvenement(3).getIdEvent()) {
			case 1 : getObjet(4).setActifObjet(true); getObjet(5).setActifObjet(true); getObjet(7).setActifObjet(true); break; 
			//attaque de pirate !
			case 2 : getObjet(0).setActifObjet(true); getObjet(1).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//problème moteur !
			case 3 : getObjet(2).setActifObjet(true); getObjet(1).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//moteur sans energie !
			case 4 : getObjet(5).setActifObjet(true); getObjet(0).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//Super Nova ! fuir !
			case 5 : getObjet(5).setActifObjet(true); getObjet(6).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//champ d'astéroide !
			case 6 : getObjet(3).setActifObjet(true); getObjet(2).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//Humain sans energie !
			case 7 : getObjet(2).setActifObjet(true); getObjet(4).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//armes sans energie !
			case 8 : getObjet(2).setActifObjet(true); getObjet(5).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//bouclier sans energie !
			case 9 : getObjet(3).setActifObjet(true); getObjet(7).setActifObjet(true);break; 
			//problème pour les humains !
			case 0 : getObjet(6).setActifObjet(true);  getObjet(7).setActifObjet(true);break; 
			//esquive !


		}
		}
		else  {GameOver();}
	}
	if (getTimer().ecoulementTimer(getTimer().getdebut())==getTimer().getValMax())
	{
		GameOver();
	}


}

bool Jeu::toutfini() //vérifie si tout les objets ont bien été résolu
{
if (getObjet(0).getActifObjet() || getObjet(1).getActifObjet() || getObjet(2).getActifObjet() ||
getObjet(3).getActifObjet() || getObjet(4).getActifObjet() || getObjet(5).getActifObjet() ||
getObjet(5).getActifObjet() || getObjet(6).getActifObjet())
{return false;}
else {return true;}


}


void Jeu::GameOver() //s'active en cas de perte au jeu
{
 cout<<"C'est perdu :,("<<endl;

}



