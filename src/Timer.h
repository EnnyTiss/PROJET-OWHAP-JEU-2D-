#ifndef _COMPTEREBOURS_H
#define _COMPTEREBOURS_H

#include "cassert"
#include <time.h>


class Timer {
    private:

        int val;
        int valMin;
        int valMax;
        bool actifCompteur;
        int debut;
        int decalage;

    public:

        Timer();
        Timer(int val, int valMin, int valMax, bool actifCompteur);
        void reinitialiser();
        void setVal(int v);
        void setActif(bool b);
        int getValMax() const;
        int getdebut() const;
        int ecoulementTimer(int debut) const;
        int getDecalage() const;
        void setDecalage(int v);
        bool getActif() const;
};


#endif