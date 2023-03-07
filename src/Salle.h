#ifndef _SALLE_H
#define _SALLE_H

#include "Objet.h"
#include "Couleur.h"

class Salle {
    private:
    int idSalle;
    int dimX;
    int dimY;
    int nbObjet;
    Couleur couleurSalle;
    std::vector<Objet> Objets;

    public:
    Salle();
    Salle(int id, int X, int Y, int nbObj, Couleur cSalle);
    ~Salle();
    void setDimX(int X);
    void setDimY(int Y);
    //void setNbObjet(int nbObj);
    void setCouleurSalle(Couleur couleur);
    int getSalle() const;
    int getNbObjet() const;
    Objet& getObjet(Objet objet) const;
   
};


#endif