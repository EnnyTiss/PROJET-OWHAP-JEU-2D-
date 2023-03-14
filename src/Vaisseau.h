#ifndef _VAISSEAU_H
#define _VAISSEAU_H
#include <cassert>

/**
@brief La classe Vaisseau contient ses dimensions et un tab 2D de cases (une case=1 char)
*/
class Vaisseau {

private :

	int m_dimx;
	int m_dimy;
	char tab[10][37];
   

public :
    


    /**
    @brief <B>Construit</B> un objet Vaisseau.
    Le constructeur remplit dimx et dimy et les cases du tableau tab avec un Vaisseau par défaut.
    @bug S'il y a un bug dans le constructeur, je peux le signaler ici ...
    */
    Vaisseau();


 

   

    /**
    @brief Renvoie le type d'objet se trouvant en (x,y)
    @param x : abs de la case de l'objet
    @param y : ordonnée de la case de l'objet
    */
    unsigned char getXY (const int x, const int y) const;

    /**
    @brief Renvoie la largeur du Vaisseau
    */
    int getDimX() const;



    /**
    @brief Renvoie la hauteur du Vaisseau
    */
    int getDimY () const;

    bool estPositionPersoValide (const int x, const int y) const;

    

};




#endif