#ifndef __EXPRESSION_H__
#define __EXPRESSION_H__

#include "string"
using namespace std;


class Expression{
    /**
     * Classe Expression
     * Attributs:
     *  String var : contient nom (variable) de l'expression
     *  String exp : contient l'expression non évalué associé à la variable
     */
  private:
    string var;
    string exp;
  public:
    Expression();
    Expression(string);
    Expression(string,string);
    string getVar();
    string getExp();
    float evaluer();
    bool isOp(char);
    float Operation(float ,float ,char);
    bool isBienParenthésée();
    float modulo(float,float );
};

#endif
