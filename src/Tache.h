#ifndef _TACHE_H
#define _TACHE_H
#include <cassert>
class Tache {
      
    private:
    int idTache;
    int difficulte;

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
//actions sur la tache
    void actionTache(int idT);

     
};

inline int Tache::getIdTache () const { return idTache; }
inline int Tache::getDif() const { assert(difficulte==1 || difficulte==2 || difficulte==3); return difficulte; }


#endif
