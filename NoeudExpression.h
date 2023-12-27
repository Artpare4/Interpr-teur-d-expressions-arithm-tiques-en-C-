#ifndef __NOEUDEXPRESSION_H__
#define __NOEUDEXPRESSION_H__

#include "Expression.h"

using namespace std;
class NoeudExpression{
    /**
     * Classe NoeudExpression. Représente un Noeud contenant une expression.
     * Utilisée dans les structures chaînées.
     *
     * Attribus:
     * e (Expression) : expression contenu de le Noeud
     * next (NoeudExpression * ) : Pointeur sur le prochain NoeudExpression de la structure chaînée.
     */
private:
  Expression e;
  NoeudExpression * next;

public:
    NoeudExpression(string,string);
    NoeudExpression(string);
  ~NoeudExpression();
  void setNext(NoeudExpression * );
  NoeudExpression * getNext();
  Expression getExpression();
};
#endif
