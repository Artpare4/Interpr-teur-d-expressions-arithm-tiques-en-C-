#include "PileReel.h"
#include <iostream>

/**
 * Constructeur par défaut de la classe PileReel.
 * Créé une pile vide.
 */
PileReel::PileReel(){
  this->FirstIn=nullptr;
};

/**
 * Méthode de la classe PileReel. Cette méthode retourne un booléen vérifiant si oui ou non
 * la pile est vide.
 * @return (bool)
 */
bool PileReel::isEmpty(){
  return this->FirstIn==nullptr;
}

/**
 * Méthode de la classe PileReel. Cette méthode empile un réel dans la pile en créant un nouveau
 * NoeudReel contenant le réel.
 *
 * @param i (float) : réel à empiler
 */
void PileReel::empiler(float i){
    NoeudReel *n= new NoeudReel(i);
    NoeudReel *old= this->FirstIn;
  this->FirstIn=n;
  this->FirstIn->setNext(old);
}

/**
 * Méthode de la classe PileChar. Cette méthode dépiler le NoeudReel en haut de la pile.
 * Si la pile est vide, cela retourne une erreur.
 * Sinon, ne retourne rien.
 */
void PileReel::depiler()throw (std::out_of_range){
  if(isEmpty())
    throw std::out_of_range ("La pile est vide");
    NoeudReel *n=this->FirstIn;
  this->FirstIn=this->FirstIn->getNext();
  delete n;
}

/**
 * Méthode de la classe PileReel. Retourne un pointeur sur le dernier NoeudReel rentré dans le pile.
 * @return (NoeudReel *)
 */
NoeudReel * PileReel::getFirstIn(){
  return this->FirstIn;
}
