#include "Objet.h"
#include <iostream>

    Objet::Objet() {idObjet=0; 
    actifObjet=false; 
    posObjet.x=0; 
    posObjet.y=0; 

    };
    /*
    Objet::Objet(int idOb,  bool actifOb, int posObX, int posObY) 
    { idObjet=idOb; 
    actifObjet=actifOb; 
    posObjetX=posObX; 
    posObjetY=posObY;}*/


    
    void Objet::setObjet(int id, bool b, int x, int y) 
    {
    idObjet=id; 
    actifObjet=b; 
    posObjet.x=x; 
    posObjet.y=y;
    }
    int Objet::getIdObjet() const {return idObjet;}
    bool Objet::getActifObjet() const { return actifObjet;}
    //int Objet::getPosObjetX() const {return posObjetX;}
    Vec2D Objet::getPosObjet() const {return posObjet;}

    void Objet::setActifObjet(bool b) 
    {
        actifObjet=b;
    }

