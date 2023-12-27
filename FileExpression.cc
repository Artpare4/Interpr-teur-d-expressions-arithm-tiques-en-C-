#include "FileExpression.h"
#include <iostream>

/**
 * Constructeur par défaut le la classe FileExpression. Créé une file vide.
 */
FileExpression::FileExpression(){
  this->FirstIn=nullptr;
  this->LastIn=nullptr;
};

/**
 * Méthode de la classe FileExpression. Cette méthode retourne un booléen vérifiant si oui ou non la file est vide.
 *
 * @return (bool)
 */
bool FileExpression::isEmpty(){
  return this->FirstIn==nullptr;
}
/**
 * Constructeur par copie de la classe FileExpression. Cette méthode prend en paramtère une file d'expression
 * et créée une nouvelle file en copiant les expressions de la file passée en paramètre.
 * @param f (FileExpression) : file d'expression
 */
FileExpression::FileExpression(const FileExpression & f) {
    if(f.FirstIn!= nullptr){
        NoeudExpression * NExpTpm= f.FirstIn;
        this->FirstIn= new NoeudExpression(NExpTpm->getExpression().getVar(),NExpTpm->getExpression().getExp());
        this->LastIn= this->FirstIn;
        NExpTpm=NExpTpm->getNext();

        while (NExpTpm!= nullptr){

            this->LastIn->setNext(new NoeudExpression(NExpTpm->getExpression().getVar(),NExpTpm->getExpression().getExp()));
            this->LastIn= this->LastIn->getNext();
            NExpTpm=NExpTpm->getNext();
        }

    } else{
        this->FirstIn= nullptr;
        this->LastIn= nullptr;
    }
}
/**
 * Méthode de la classe FileExpression. Cette méthode insert une expression dans la file avec les informations passées en paramtère.
 *
 * @param var (string): variable
 * @param exp (string) : expression
 */
void FileExpression::insert(string var,string exp){
  NoeudExpression *n= new NoeudExpression(var,exp);
  if(isEmpty())
    this->FirstIn=n;
  else{
    this->LastIn->setNext(n);
  }
  this->LastIn=n;
}

/**
 * Méthode de la classe FileExpression. Cette méthode défile l'élément en tête de file .
 * Si la file est vide, une erreur est retournée.
 * Sinon,ne retourne rien.
 */
void FileExpression::defiler() throw (std::out_of_range){
    if(isEmpty())
      throw std::out_of_range ("La file est vide");
    NoeudExpression * n =this->FirstIn;
    this->FirstIn=this->FirstIn->getNext();
	delete n;
}

/**
 * Méthode de la classe FileExpression. Cette méthode retourne le dernier élément rentrée dans la file.
 * Retourn un pointeur sur un NoeudExpression.
 * @return (NoeudExpression *)
 */
NoeudExpression * FileExpression::getLastIn(){
  return this->LastIn;
}

/**
 * Méthode de la classe FileExpression. Cette méthode retourne l'éléments le plus ancien rentrée dans la liste.
 * Retourn un pointeur sur un NoeudExpression.
 * @return (NoeudExpression *)
 */
NoeudExpression * FileExpression::getFirstIn(){
  return this->FirstIn;
}

