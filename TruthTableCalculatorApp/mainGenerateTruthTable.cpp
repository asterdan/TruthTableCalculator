
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <map>
#include <vector>
#include <algorithm>
#include <stack>
#include "BitOperation.h"
#include "InfixToPostfix.h"
#include "TruthTable.h"

using namespace std;


class MapToMatrix {

public:
    static vector<vector<string>> convert(map<string,vector<int>> &input){

        map<int,string> x;
        string t = "T";
        string f = "F";
        x.insert(pair<int,string>(0,f));
        x.insert(pair<int,string>(1,t));

        vector<vector<string>> table;

        map<string,vector<int>>::reverse_iterator it;

        for (it=input.rbegin();it!=input.rend();it++){
            vector<string> arr;
            arr.push_back(it->first);
            for (int i=0;i<input[it->first].size();i++){
                arr.push_back(x[input[it->first][i]]);
            }
            table.push_back(arr);
        }

        return table;
    }

};

class MatrixPrinter {
public:
    static void printMatrix(vector<vector<string>> &m){
            for (int i=0;i<m[0].size();i++){

                for (int j=0;j<m.size();j++){
                    cout << "\t" << m[j][i] << " ";
                }
                cout << endl;
        }
    }
};

int main()
{


    cout << "Truth table calculator." <<  endl;
    cout << "{ ~ is Negation , ^ is AND , | is OR ," << endl;
    cout << " > is Condition , = is Equivalence }" << endl;
    cout << endl;
    cout << "Enter proposition:";
    string proposition;
    cin >> proposition;


    map<string,vector<int>> truthtable = TruthTable::calculate(proposition);

    vector<vector<string>> table = MapToMatrix::convert(truthtable);

    MatrixPrinter::printMatrix(table);





    return 0;
}
