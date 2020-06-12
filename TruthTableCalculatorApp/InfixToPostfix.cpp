#include "InfixToPostfix.h"

string InfixToPostfix::convert(string compound){
     for (int i=0;i<compound.size();i++){
            char c = compound.at(i);
            switch(c){
            case '(':
                s.push(c);
                break;
            case ')':
                endParenthesis();
                break;
            case '~':
                pushOperator(c,1);
                break;
            case '^':
                pushOperator(c,2);
                break;
            case '|':
                pushOperator(c,3);
                break;
            case '>':
                pushOperator(c,4);
                break;
            case '=':
                pushOperator(c,5);
                break;
            default:
                output+=c;
                break;

            }
        }

        while (!s.empty()){
            char x = s.top();
            s.pop();
            output+=x;
        }

        return output;
}

void InfixToPostfix::pushOperator(char opThis,int precedence){
     if(s.empty()){
            s.push(opThis);

        }
        else {
            while(!s.empty()){
                char x = s.top();
                s.pop();
                if(x=='('){
                    s.push(x);
                    break;
                }
                else {
                    int precedence2;
                    if(x=='~'){
                        precedence2 = 1;
                    }
                    else if (x=='^'){
                        precedence2 = 2;
                    }
                    else if (x=='|'){
                        precedence = 2;
                    }
                    else if (x=='>'){
                        precedence = 3;
                    }
                    else if (x=='='){
                        precedence = 3;
                    }

                    if(precedence2<precedence){
                        s.push(x);
                        break;
                    }
                    else {
                        output+=x;
                    }
                }

            }
            s.push(opThis);
        }
}


void InfixToPostfix::endParenthesis(){
    while(!s.empty()){
            char x = s.top();
            s.pop();
            if(x=='('){
                break;
               }
               else {
                output+=x;
               }

        }
}
