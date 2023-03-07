#include "Salle.h"
using namespace std;


Salle(){idSalle =0; dimX=dimY=10; nbObjet=1; couleurSalle= Couleur(0,0,0); Objets=vector();}
Salle(int idS, int X, int Y, int nbObj, Couleur cSalle) {
idSalle=id; dimX=X; dimY=Y; nbObjet=nbObj; couleurSalle=cSalle; Objets=vector(nbObj,Objet);
}
~Salle(){idSalle =0; dimX=dimY=0; nbObjet=0; couleurSalle= Couleur(255,255,255);Objets=~vector();}
void Salle::setDimX(int X) {DimX=X;}
void Salle::setDimY(int Y){DimY=Y;}
//void Salle::setNbObjet(int nbObj);
void Salle::setCouleurSalle(Couleur couleur){couleurSalle=couleur;}
int Salle::getIdSalle() const {return idSalle;}
int Salle::getNbObjet() const {return nbObjet;}
Objet& Salle::getIdObjet(Objet objet) const {return objet.idObjet;}
