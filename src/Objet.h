#ifndef _OBJET_H
#define _OBJET_H

class Objet {
    private:

    int idObjet;
    Couleur couleurObjet;
    bool actifObjet;
    Vec2D posObjet;
    Tache tacheObjet;

    public:
//constructeurs/destructeurs
    Objet();
    Objet(int idObjet, Couleur couleurObjet, bool actifObjet, Vec2D posObjet);
    ~Objet();
//fonctions memnbres
    //mutateurs
    void setCouleurObjet(Couleur couleurObj);
    void setActifObjet(bool actifObj);
    void setPosObjet(Vec2D posObj);
    void setTacheObjet(Tache tacheObj);
    //accesseurs
    int getIdObjet() const;
    Couleur& getCouleurObjet() const;
    bool getActifObjet() const;
    Vec2D getPosObjet() const;
    Tache getTacheObjet() const;
    //actions sur l'objet
    void clignotement(Couleur couleurObj, bool actifObj);
};


#endif