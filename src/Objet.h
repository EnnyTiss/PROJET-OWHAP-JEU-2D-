#ifndef _OBJET_H
#define _OBJET_H
#include "Vaisseau.h"


class Objet {
    private:

    int idObjet;
    bool actifObjet;
    int posObjetX;
    int posObjetY;
    //Tache tacheObjet;

    public:
//constructeurs/destructeurs
    Objet();
    Objet(int idObjet,  bool actifObjet, int posObjetX, int posObjetY);
    //~Objet();
//fonctions memnbres
    //mutateurs
    void setActifObjet(bool b);
    void setObjet(int id, bool b, int x, int y);
    //void setTacheObjet(Tache tacheObj);
    //accesseurs
    int getIdObjet() const;
    bool getActifObjet() const;
    int getPosObjetX() const;
    int getPosObjetY() const;
    //Tache getTacheObjet() const;
    //actions sur l'objet
};


#endif