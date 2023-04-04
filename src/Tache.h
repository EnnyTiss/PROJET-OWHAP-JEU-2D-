#ifndef _TACHE_H
#define _TACHE_H
#include <cassert>
#include <random>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;


class Tache {
      
    private:
    int idTache;
    int difficulte;

    string resString;
    string quesString;


    void Combinaison(); //saisie combinaison de touches
    void RecopierCode(); //saisir le code affiché à l'écran
    void Calcul(); //résoudre un calcul simple
    void SpamTouche(); //appuyer sur une touche un nombre de fois
    void Question(); //répondre à une question 
    void RecopierMot(); //saisir le mot affiché à l'écran
    void AppuiTouche(); //appuyer sur une touche 
    void Findevent(); //bonus de fin en avance

    public:
//constructeurs/destructeur
    Tache();
    Tache( int difficulte);
//accesseurs
    int getIdTache() const;
    int getDif() const;
    string getQuesString () const;
    string getResString () const;

//actions sur la tache
    void actionTache(int idT);

     
};

inline int Tache::getIdTache () const { return idTache; }
inline int Tache::getDif() const { assert(difficulte==1 || difficulte==2 || difficulte==3); return difficulte; }
inline string Tache::getQuesString () const { return quesString; }
inline string Tache::getResString () const { return resString; }



#endif
