#include "PileChar.h"
#include <iostream>

/**
 * Constructeur par défaut de la classe PileChar.
 * Créé une pile vide.
 */
PileChar::PileChar(){
  this->FirstIn=nullptr;
};

/**
 * Méthode de la classe PileChar. Cette méthode retourne un booléen vérifiant si oui ou non
 * la pile est vide.
 * @return (bool)
 */
bool PileChar::isEmpty(){
  return this->FirstIn==nullptr;
}

/**
 * Méthode de la classe PileChar. Cette méthode empile un caractère dans la pile en créant un nouveau
 * Noeud contenant le caractère.
 *
 * @param c (char) : caractère à empiler
 */
void PileChar::empiler(char c){
  Noeud *n= new Noeud(c);
  Noeud *old= this->FirstIn;
  this->FirstIn=n;
  this->FirstIn->setNext(old);
}

/**
 * Méthode de la classe PileChar. Cette méthode dépiler le noeud en haut de la pile.
 * Si la pile est vide, cela retourne une erreur.
 * Sinon, ne retourne rien.
 */
void PileChar::depiler()throw (std::out_of_range){
  if(isEmpty())
    throw std::out_of_range ("La pile est vide");
  Noeud *n=this->FirstIn;
  this->FirstIn=this->FirstIn->getNext();
  delete n;
}

/**
 * Méthode de la classe PileChar. Retourne un pointeur sur le dernier noeud rentré dans le pile.
 * @return (Noeud *)
 */
Noeud * PileChar::getFirstIn(){
  return this->FirstIn;
}
