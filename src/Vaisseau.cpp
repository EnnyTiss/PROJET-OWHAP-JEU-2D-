#include "Vaisseau.h"
#include <cassert>
#include <iostream>

using namespace std;




Vaisseau::Vaisseau() {
	m_dimy=37;
	m_dimx=10;
	const char tabX[10][37]= {
 "##############################      ",
 "#0...#.....3....#...........4#      ",
 "#....#..........#............#      ",
 "#....#####..#########...############",
 "#...............7..................#",
 "#.................................6#",
 "#....#####..#########...############",
 "#....#..........#............#      ",
 "#1...#....2.....#...........5#      ",
 "##############################      "
	};


	for(int x=0;x<m_dimx;x++)
		for(int y=0;y<m_dimy;y++)
		{Vaisseau::tab[x][y]=tabX[x][y];
		}

	

}

bool Vaisseau::estPositionPersoValide (const int x, const int y) const {
	//int num = (int) tab[x][y];
	return ((x>=0) && (x<m_dimx) && (y>=0) && (y<m_dimy) && (tab[x][y]=='.'));
	cout<<"c valide"<<endl;;
}


int Vaisseau::getDimX () const { return m_dimx; }

int Vaisseau::getDimY () const {	return m_dimy; }

unsigned char Vaisseau::getXY (const int x, const int y) const
{
	return Vaisseau::tab[x][y];
}
