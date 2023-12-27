#ifndef __PILECHAR_H__
#define __PILECHAR_H__

#include "Noeud.h"
#include <stdexcept>

class PileChar{
    /**
     * Classe PileChar. Représente un pile de caractères
     *
     * Attributs:
     * FirstIn (Noeud * ) : pointeur sur le dernier noeud entré dans la pile
     */
private:
  Noeud * FirstIn;
public:
  PileChar();
  void empiler(char c);
  void depiler() throw (std::out_of_range);
  bool isEmpty();
  Noeud * getFirstIn();
};





#endif
