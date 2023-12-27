#include "Expression.h"

#include "PileReel.h"
#include "PileChar.h"

#include <iostream>

using namespace std;
/**
 * Constructeur par défaut de la classe Expression. Cette méthode demande à l'utilisateur de rentrer un expression sour la forme
 * Ex: a=2+2
 * Et créer un objet contenant la variable et l'expression passé par l'utilisateur.
 */
Expression::Expression(){
  cout<<"Entrez votre expression (Ex: a=1+1)"<<'\n';
  string exp2;
  cin>>exp2;
  int indexEgal=exp2.rfind('=');
  //variable
  this->var=exp2.substr(0,indexEgal);
  //expression
  this->exp=exp2.substr(indexEgal+1);
}

/**
 * Constructeur de la classe Expression. Cette méthode prend en paramètre un string sous la forme
 * Ex: a=2+2
 * Et créer un objet contenant la variable et l'expression de la chaîne de caractères.
 *
 * @param s (string): chaîne de caractères
 */
Expression::Expression(string s) {
    int indexEgal=s.rfind('=');
    this->var=s.substr(0,indexEgal);
    this->exp=s.substr(indexEgal+1);
}
/**
 * Constructeur de la classe Expression. Cette méthode prend en paramètre un string correspondant à la variable et un string correspondant à l'expression
 * Ex: var:a   exp:2+2
 * Et créer un objet contenant la variable et l'expression passée un paramètre.
 *
 * @param var1 (string): variable
 * @param exp1 (string) : expression
 */
Expression::Expression(string var1, string exp1):var(var1),exp(exp1) {
}

/**
 * Méthode de la classe Expression. Cette méthode retourn un booléen qui indique si oui ou non le caractère passé en paramètre est un opérateur (+,-,*,/,%).
 * @param c (char) : caractère
 * @return (bool)
 */
bool Expression::isOp(char c) {
    return c=='+'||c=='-'||c=='*'||c=='/'||c=='%';
}

/**
 * Méthode de la classe Expression. Cette méthode prend en paramètre 2 réels , les convertis en entier
 * et fait un calcul modulo (var1%var2) et retourne le résultat sous forme de réel.
 *
 * @param val1 (float): réel 1
 * @param val2 (float): réel 2
 * @return (float)
 */
float Expression::modulo(float val1, float val2) {
    int x=(int)val1;
    int y=(int) val2;
    int res=x%y;
    return (float)res;
}
/**
 * Méthode de la classe Expression. Cette méthode retoune un float résutant du calcul entre les 2 valeurs passées en paramtère et l'opérateur.
 * @param x (float) : réel 1
 * @param y (float) : réel 2
 * @param op (char) : opérateur
 * @return (float)
 */
float Expression::Operation(float x, float y, char op) {
    switch (op) {
        case '+':
            return x+y;
        case '-':
            return y-x;
        case '*':
            return x*y;
        case '/':
            return y/x;
        case '%':
            return modulo(y,x);
    }
}

bool Expression::isBienParenthésée() {
    int nbParD=0;
    int nbParG=0;
    int i=0;
    while(i<this->exp.length()){
        if(this->exp[i]=='('){
            nbParG+=1;
        }else if(this->exp[i]==')'){
            nbParD+=1;
        }
        i+=1;
    }
    return nbParD==nbParG;
}

float Expression::evaluer(){
  PileChar op;
  PileReel numbers;

  int i=0;
  int length= this->exp.length();
    while (i<length){
        char car= this->exp[i];
        if(isdigit(car)){ //si c'est un chiffre
            if(isdigit(this->exp[i+1])){ // on regarde si les prochains caractères sont des chiffres eux aussi (dans le but de reconstituer le nombre)
                int j=i;
                while(isdigit(this->exp[j+1])){
                    j=j+1;
                }
                float val= stof(this->exp.substr(i,(j-i)+1));
                numbers.empiler(val);
                i=j+1;
            }
            else{
                float val= car -'0';
                numbers.empiler(val);
                i+=1;
            }
        }else if(car=='('){
            op.empiler(car);
            i+=1;
        } else if (car==')'){
            while(!op.isEmpty() && op.getFirstIn()->getChar()!='('){
                float val1=numbers.getFirstIn()->getVal();
                numbers.depiler();
                float val2=numbers.getFirstIn()->getVal();
                numbers.depiler();
                char operateur=op.getFirstIn()->getChar();
                op.depiler();
                numbers.empiler(Operation(val1,val2,operateur));
            }
            op.depiler();
            i+=1;
        } else if(isOp(car)) {
            while(!op.isEmpty() && (op.getFirstIn()->getChar()=='*'||op.getFirstIn()->getChar()=='/')&&(car=='+'||car=='-')){
                float val1=numbers.getFirstIn()->getVal();
                numbers.depiler();
                float val2=numbers.getFirstIn()->getVal();
                numbers.depiler();
                char operateur=op.getFirstIn()->getChar();
                op.depiler();
                numbers.empiler(Operation(val1,val2,operateur));
            }
            op.empiler(car);
            i+=1;
        }
    }

    while (!op.isEmpty()){
        float val1=numbers.getFirstIn()->getVal();
        numbers.depiler();
        float val2=numbers.getFirstIn()->getVal();
        numbers.depiler();
        char operateur=op.getFirstIn()->getChar();
        op.depiler();
        numbers.empiler(Operation(val1,val2,operateur));
    }
    return numbers.getFirstIn()->getVal();
}

/**
 * Méthode de la classe Expression. Retourne le contenu de l'attribut var.
 * @return (string)
 */
string Expression::getVar() {
    return this->var;
}

/**
 * Méthode de la classe Expression. Retourne le contenu de l'attribut exp.
 * @return (string)
 */
string Expression::getExp() {
    return this->exp;
}
