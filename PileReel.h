#ifndef __PILEREEL_H__
#define __PILEREEL_H__

#include "NoeudReel.h"
#include <stdexcept>

class PileReel{
    /**
     * Classe PileReel. Représente un pile de réels.
     *
     * Attributs:
     * FirstIn (NoeudReel * ) : pointeur sur le dernier NoeudReel entré dans la pile
     */
private:
  NoeudReel * FirstIn;
public:
  PileReel();
  void empiler(float );
  void depiler() throw (std::out_of_range);
  bool isEmpty();
  NoeudReel * getFirstIn();
};





#endif
