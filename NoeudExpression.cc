#include "NoeudExpression.h"
#include <iostream>


/**
 * Constructeur de la classe NoeudExpression. Cette méthode prend en paramtère une chaîne de caractères et créé un nouveau NoeudExpression contenant
 * une expression avec la chaîne c.
 * Par défaut le pointeur sur le prochain NoeudExpression est null.
 * @param c (string): chaîne de caractères pour créer l'expression
 */
NoeudExpression::NoeudExpression(string c){
  this->e=Expression(c);
  this->next=nullptr;
}
/**
 * Constructeur de la classe NoeudExpression. Cette méthode construit un NoeudExpression contenant une expression avec les valeur passées en paramtère.
 * Par défaut le pointeur sur le prochain NoeudExpression est null.
 * @param var (string) : variable
 * @param exp (string) : expression
 */
NoeudExpression::NoeudExpression(string var,string exp):e(Expression(var,exp)),next(nullptr){
}

/**
 * Destructeur de la classe NoeudExpression.
 */
NoeudExpression::~NoeudExpression(){
  this->next=nullptr;
}

/**
 * Méthode de la classe NoeudExpression. Cette méthode prend en paramtère un pointeur sur un NoeudExpression et l'associe à l'attribut next.
 * @param n (NoeudExpression * ) : pointeur sur un NoeudExpression
 */
void NoeudExpression::setNext(NoeudExpression * n){
  this->next=n;
}


/**
 * Méthode de la classe NoeudExpressino. Cette méthode retourne le pointeur sur le prochain NoeudExpression.
 * @return (NoeudExpression *)
 */
NoeudExpression * NoeudExpression::getNext(){
  return this->next;
}

/**
 * Méthode de la classe NoeudExpression. Cette méthode retourne l'expression contenu dans le NoeudExpression.
 * @return (Expression)
 */
Expression NoeudExpression::getExpression(){
  return this->e;
}
