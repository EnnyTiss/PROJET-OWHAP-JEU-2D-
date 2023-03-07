#ifndef _TACHE_H
#define _TACHE_H

class Tache {
      
    private:
    int idTache;
    int dureeTache;

    public:
//constructeurs/destructeur
    Tache();
    Tache(int idT, int dureeT);
    ~Tache();
//mutateurs
    void setDureeTache(int dureeT);
//accesseurs
    int getIdTache() const;
    int getDureeTache() const;
//actions sur la tache
    void actionTache();
      
}

#endif
