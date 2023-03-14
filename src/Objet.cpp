#include "Objet.h"
#include <iostream>

    Objet::Objet() {idObjet=0; 
    actifObjet=false; 
    posObjetX=0; 
    posObjetY=0;
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
    posObjetX=x; 
    posObjetY=y;
    }
    int Objet::getIdObjet() const {return idObjet;}
    bool Objet::getActifObjet() const { return actifObjet;}
    int Objet::getPosObjetX() const {return posObjetX;}
    int Objet::getPosObjetY() const {return posObjetY;}

    void Objet::setActifObjet(bool b) 
    {
        actifObjet=b;
        std::cout<<"ça change l'actif";
    }

