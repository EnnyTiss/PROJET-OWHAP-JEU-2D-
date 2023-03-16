#ifndef _TACHE_H
#define _TACHE_H

class Tache {
      
    private:
    int idTache;

    public:
//constructeurs/destructeur
    Tache();
    Tache(int idT);
    ~Tache();
//accesseurs
    int getIdTache() const;
//actions sur la tache
    void actionTache();
      
};

inline int Tache::getIdTache () const { return idTache; }

#endif
