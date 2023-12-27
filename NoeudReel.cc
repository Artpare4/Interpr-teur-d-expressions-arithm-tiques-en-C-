#include "NoeudReel.h"
#include <iostream>

/**
 * Constructeur de la classe NoeudReel. Cette méthode prend en paramtère un réel et créé un nouveau NoeudRéel contenant ce réel.
 * Par défaut le pointeur sur le prochain NoeudRéel est null.
 * @param i (float): réel à stocker
 */
NoeudReel::NoeudReel(float i){
  this->i=i;
  this->next=nullptr;
}

/**
 * Destructeur de la classe NoeudReel.
 */
NoeudReel::~NoeudReel(){
  this->next=nullptr;
}

/**
 * Méthode de la classe NoeudReel. Cette méthode prend en paramtère un pointeur sur un NoeudReel et l'associe à l'attribut next.
 * @param n (NoeudReel * ) : pointeur sur un NoeudReel
 */
void NoeudReel::setNext(NoeudReel * n){
  this->next=n;
}

/**
 * Méthode de la classe NoeudReel. Cette méthode retourne le pointeur sur le prochain NoeudReel.
 * @return (NoeudReel *)
 */
NoeudReel * NoeudReel::getNext(){
  return this->next;
}

/**
 * Méthode de la classe NoeudReel. Cette méthode retourne le réel contenu dans le NoeudReel.
 * @return (float)
 */
float NoeudReel::getVal(){
  return this->i;
}
