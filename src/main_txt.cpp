#include "Jeu.h"
#include "winTxtO.h"
#include "txtJeuO.h"
using namespace std;
#include <iostream>


int main(void)
{
    Jeu j;
    j.getObjet(1).setActifObjet(true);
    txtBoucle(j);
    /*for (int i=0; i<v.getDimX(); i++)
    {
        for (int j=0; j<v.getDimY(); j++)
        {
            cout<<v.getXY(i,j);
        }
        cout<<endl;
    }*/
    return 0;
}