#ifndef _VAISSEAU_H
#define _VAISSEAU_H
#include <cassert>

/**
@brief La classe Vaisseau contient ses dimensions et un tab 2D de cases (une case=1 char)
*/
class Vaisseau {

private :

    enum TypeCase { SPACE=' ', WALL='#', DOT='.' };         // Les enum sont d'habitude initialisé avec des nombres, ici on a une équivalence caractère/nombre

	int m_dimx;
	int m_dimy;
	//char m_ter [100][100];
    TypeCase m_ter[100][100];

public :

    /**
    @brief <B>Construit</B> un objet Vaisseau.
    Le constructeur remplit dimx et dimy et les cases du tableau ter avec un Vaisseau par défaut.
    @bug S'il y a un bug dans le constructeur, je peux le signaler ici ...
    */
    Vaisseau();


 

    /**
    @brief Renvoie le type d'objet se trouvant en (x,y)
    @param x : abs de la case de l'objet
    @param y : ordonnée de la case de l'objet
    */
    TypeCase getXY (const int x, const int y) const;

    /**
    @brief Renvoie le type d'objet se trouvant en (x,y)
    @param x : abs de la case de l'objet
    @param y : ordonnée de la case de l'objet
    */
    unsigned char getXYasChar (const int x, const int y) const;

    /**
    @brief Renvoie la largeur du Vaisseau
    */
    int getDimX () const;

    /**
    @brief Renvoie la hauteur du Vaisseau
    */
    int getDimY () const;

};


inline int Vaisseau::getDimX () const { return m_dimx; }

inline int Vaisseau::getDimY () const {	return m_dimy; }

inline Vaisseau::TypeCase Vaisseau::getXY (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<m_dimx);
	assert(y<m_dimy);
	return m_ter[x][y];
}

inline unsigned char Vaisseau::getXYasChar (const int x, const int y) const {
	assert(x>=0);
	assert(y>=0);
	assert(x<m_dimx);
	assert(y<m_dimy);
    return (char)(m_ter[x][y]);     // ceci ne marche que dans notre cas particulier, car l'enum est initialisé avec les codes ascii
}


#endif