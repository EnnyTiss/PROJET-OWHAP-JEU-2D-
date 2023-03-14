#ifndef _COMPTEREBOURS_H
#define _COMPTEREBOURS_H

#include "cassert"

class Timer {
    private:

        int val;
        int valMin;
        int valMax;
        bool actifCompteur;

    public:

        Timer();
        Timer(int val, int valMin, int valMax, bool actifCompteur);
//+ incrementer(): bool
//+ decrementer(): bool
        void reinitialiser();
        void setVal(int v);
        void setActif(bool b);

        void GameOver();
        int ecoulementTimer();
};

#endif