#ifndef __NOEUDREEL_H__
#define __NOEUDREEL_H__

class NoeudReel{
    /**
     * Classe NoeudReel. Représente un Noeud contenant un réel.
     * Utilisée dans les structures chaînées.
     *
     * Attribus:
     * i (float) : réel contenu de le Noeud
     * next (NoeudReel * ) : Pointeur sur le prochain NoeudRéel de la structure chaînée.
     */
private:
  float i;
  NoeudReel * next;

public:
    NoeudReel(float);
  ~NoeudReel();
  void setNext(NoeudReel * );
    NoeudReel * getNext();
  float getVal();
};
#endif
