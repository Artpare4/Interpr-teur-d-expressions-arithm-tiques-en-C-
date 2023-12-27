#include "Noeud.h"
#include <iostream>

/**
 * Constructeur de la classe Noeud. Cette méthode prend en paramtère un caractère et créé un nouveau Noeud contenant ce caractère.
 * Par défaut le pointeur sur le prochain Noeud est null.
 * @param c (char): caractère à stocker
 */
Noeud::Noeud(char c){
  this->c=c;
  this->next=nullptr;
}

/**
 * Destructeur de la classe Noeud.
 */
Noeud::~Noeud(){
  this->next=nullptr;
}

/**
 * Méthode de la classe Noeud. Cette méthode prend en paramtère un pointeur sur un Noeud et l'associe à l'attribut next.
 * @param n (Noeud * ) : pointeur sur un Noeud
 */
void Noeud::setNext(Noeud * n){
  this->next=n;
}

/**
 * Méthode de la classe Noeud. Cette méthode retourne le pointeur sur le prochain Noeud.
 * @return (Noeud *)
 */
Noeud * Noeud::getNext(){
  return this->next;
}

/**
 * Méthode de la classe Noeud. Cette méthode retourne le caractère contenu dans le Noeud.
 * @return (char)
 */
char Noeud::getChar(){
  return this->c;
}
