#ifndef __FILEEXPRESSION_H__
#define __FILEEXPRESSION_H__

#include "NoeudExpression.h"
#include <stdexcept>
using namespace std;

class FileExpression{
    /**
     * Classe FileExpression. Représente une file contenant des expressions.
     *
     * Attributs:
     * FirstIn (NoeudExpression *): Premier noeud rentré dans la file
     * LastIn (NoeudExpression *) : Dernier noeud renté dans le file
     */
  private:
    NoeudExpression * FirstIn;
    NoeudExpression * LastIn;
public:
    FileExpression();
    FileExpression(const FileExpression & );
  void insert(string, string);
  void defiler() throw (std::out_of_range);
  bool isEmpty();
  NoeudExpression * getLastIn();
  NoeudExpression * getFirstIn();
};





#endif
