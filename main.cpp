#include "Expression.h"
#include "FileExpression.h"
#include "PileChar.h"
#include "PileReel.h"

#include <iostream>

using namespace std;

/**
 * Fonction évaluer
 *
 * @param Expression : expression à evaluer
 * @param FileExpression :
 * @return float : Résultat de l'évaluation de l'expression arithmétique
 */
float evaluer( Expression ,FileExpression& );
bool verifExpression(Expression & , const FileExpression &);

int main(){
    string testSortie;
    string testEvaluation;
    FileExpression f1;
    do{
        Expression exp1;
        if(exp1.isBienParenthésée()){
            if(verifExpression(exp1,f1)){
                cout<<"Voulez vous obtenir le résultat de votre expression ? (Insérez \"oui\" pour avoir le résultat sinon insérez \"non\")"<<'\n';
                cin>>testEvaluation;
                if(testEvaluation=="oui"){
                    cout<<"Résultat:"<<'\n';
                    cout<<evaluer(exp1,f1)<<'\n';
                }
                f1.insert(exp1.getVar(),exp1.getExp());
                cout<<"Voulez-vous continuer à rentre une expression ? (Insérez \"stop\" pour arrêter le programme sinon insérez \"continue\" )"<<'\n';
                cin>>testSortie;
            } else{
                cout<<"Veuillez re-retrer votre expression correctement"<<'\n';
            }
        }else{
            cout<<"                      "<<'\n';
            cout<<"Votre expression est mal parenthésée"<<'\n';
            cout<<"Veuillez re-retrer votre expression correctement"<<'\n';
        }
    } while (testSortie!="stop");
  return 0;
}

/**
 * Fonction évaluer. Cette fonction prend en paramètre une expression à évaluer et une file d'Expression
 * contentant les expressions précédements écrits par l'utilisateur.
 * Cette fonction retourne le résultat de l'expression arithmétique
 *
 * @param expression (Expression) :expression à evaluer
 * @param fileExp (FileExpression) : file d'expression
 * @return float : Résultat de l'évaluation de l'expression arithmétique
 */
float evaluer( Expression  expression, FileExpression&  fileExp){
    PileChar op;
    PileReel numbers;

    int i=0;
    int length= expression.getExp().length();
    while (i<length){
        char car= expression.getExp()[i];
        if(isdigit(car)){
            if(isdigit(expression.getExp()[i+1])){
                int j=i;
                while(isdigit(expression.getExp()[j+1])){
                    j=j+1;
                }
                float val= stof(expression.getExp().substr(i,(j-i)+1));
                numbers.empiler(val);
                i=j+1;
            }
            else{
                float val= car -'0';
                numbers.empiler(val);
                i+=1;
            }
        }else if(isalpha(car)){
            FileExpression tmp(fileExp);
            bool testSortie= true;
            bool contient= false;
            string test(1,car);
            while(!tmp.isEmpty() && testSortie){
                if(test==tmp.getFirstIn()->getExpression().getVar()){
                    numbers.empiler(evaluer(tmp.getFirstIn()->getExpression(),fileExp));
                    testSortie= false;
                    contient= true;
                } else{
                    tmp.defiler();
                }

            }
            i+=1;
        }
        else if(car=='('){
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
                numbers.empiler(expression.Operation(val1,val2,operateur));
            }
            op.depiler();
            i+=1;
        } else if(expression.isOp(car)) {
            while(!op.isEmpty() && (op.getFirstIn()->getChar()=='*'||op.getFirstIn()->getChar()=='/')&&(car=='+'||car=='-')){
                float val1=numbers.getFirstIn()->getVal();
                numbers.depiler();
                float val2=numbers.getFirstIn()->getVal();
                numbers.depiler();
                char operateur=op.getFirstIn()->getChar();
                op.depiler();
                numbers.empiler(expression.Operation(val1,val2,operateur));
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
        numbers.empiler(expression.Operation(val1,val2,operateur));
    }
    return numbers.getFirstIn()->getVal();
}


/**
 * Fonction verifExpression. Cette fonction retourne un booléen indiquant si oui ou non les variables
 * contenu dans l'expression on été précédement définies.
 * @param expression (Expression) : expression à vérifier
 * @param fileExpression (FileExpression): file d'expression
 * @return (bool)
 */
bool verifExpression( Expression & expression , const FileExpression & fileExpression){
    bool res=true;
    for(int i=0;i<expression.getExp().length();i++){
        if(isalpha(expression.getExp()[i])){
            string car(1,expression.getExp()[i]);
            FileExpression tmp(fileExpression);
            bool testContient=false;
            while(!tmp.isEmpty() && !testContient){
                if(tmp.getFirstIn()->getExpression().getVar()==car){
                    testContient= true;
                } else{
                    tmp.defiler();
                }
            }
            if(!testContient){
                res= false;
                cout<<"                      "<<'\n';
                cout<<"La variable "<<car<<" n'a pas été défini précédement"<<'\n';
                i=expression.getExp().length();
            }
        }
    }
    return res;
}