#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#ifndef InfixToPostfix_H
#define InfixToPostfix_H
using namespace std;
class InfixToPostfix{

public:
    stack<char> s;
    string output;
    string convert(string compound);
    void pushOperator(char opThis,int precedence);
    void endParenthesis();
};

#endif // InfixToPostfix_H
