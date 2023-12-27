#ifndef __NOEUD_H__
#define __NOEUD_H__



class Noeud{

    /**
     * Classe Noeud. Représente un Noeud contenant un caractère.
     * Utilisée dans les structures chaînées.
     *
     * Attribus:
     * c (char) : caractrère contenu de le Noeud
     * next (Noeud * ) : Pointeur sur le prochain Noeud de la structure chaînée.
     */
private:
  char c;
  Noeud * next;

public:
  Noeud(char);
  ~Noeud();
  void setNext(Noeud * );
  Noeud * getNext();
  char getChar();
};
#endif
