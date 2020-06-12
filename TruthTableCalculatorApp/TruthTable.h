#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#ifndef TruthTable_H
#define TruthTable_H
using namespace std;
class TruthTable {

public:
    static map<string,vector<int>> calculate(string compound);
};

#endif // TruthTable_H
