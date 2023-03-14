#ifndef _COMPTEREBOURS_H
#define _COMPTEREBOURS_H

#include "cassert"

class CompteRebours {
    private:

        int val;
        int valMin;
        int valMax;
        bool actifCompteur;

    public:

        CompteRebours();
        CompteRebours(int val, int valMin, int valMax, bool actifCompteur);
//+ incrementer(): bool
//+ decrementer(): bool
        void reinitialiser();
        void setVal(int v);
        void setActif(bool b);
        int getValMin() const;
        int getValMax() const;
        void GameOver();
        void ecoulementRebours();
}

#endif