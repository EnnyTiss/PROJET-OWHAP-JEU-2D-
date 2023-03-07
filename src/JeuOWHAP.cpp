#include "JeuOWHAP.h"

JeuOWHAP() {}
~JeuOWHAP() {}

//const Personnage& getPersonnage();
//const Danger& getDanger();
//const CompteRebours& getCompteRebours();
const Terrain& getConstVaisseau() const {return V;}
JeuOWHAP resetJeuOWHAP() {~JeuOWHAP();}