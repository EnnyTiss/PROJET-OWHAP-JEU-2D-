#ifndef _TACHE_H
#define _TACHE_H

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

    public:
//constructeurs/destructeur
    Tache();
    Tache(int idT, int difficulte);
    ~Tache();
//accesseurs
    int getIdTache() const;
//actions sur la tache
    void actionTache(int idT);

     
};

inline int Tache::getIdTache () const { return idTache; }

#endif
