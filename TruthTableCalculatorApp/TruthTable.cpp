
#include "TruthTable.h"
#include "InfixToPostfix.h"
#include "BitOperation.h"

map<string,vector<int>> TruthTable::calculate(string compound){

        map<string,vector<int>> m;
        vector<char> keys;
        int counter = 0;
        for (int i=compound.size()-1;i>-1;i--){
            char c = compound.at(i);
            if((c>='a'&&c<='z')){
                if(!(count(keys.begin(),keys.end(),c))){
                    keys.push_back(c);
                    vector<int> bits;
                    string ch;
                    ch.push_back(c);
                    m.insert(pair<string,vector<int>>(ch,bits));
                    counter++;
                }


            }
        }
        int numberOfCombinations = pow(2,counter)-1;
        for (int i=numberOfCombinations;i>=0;i--){
            bitset<64> x(i);
            int k = 0;
            map<string,vector<int>>::iterator it;
            for (it=m.begin();it!=m.end();it++){
                m[it->first].push_back(x[k]);
                k++;
            }
        }

        stack<string> s;
        InfixToPostfix converter;
        string postfix = converter.convert(compound);

        for (int i=0;i<postfix.size();i++){
            char x = postfix.at(i);
            string e;
            e.push_back(x);
            if(x>='a'&&x<='z'){
                s.push(e);
            }
            else {
                if(x=='~'){
                    string p = s.top();
                    s.pop();
                    string exp;
                    exp = "("+e+p+")";
                    vector<int> v;
                    m.insert(pair<string,vector<int>>(exp,v));
                    int length = m[p].size();
                    for (int i=0;i<length;i++){
                        int bit = BitOperation::operation(m[p][i],0,'~');
                        m[exp].push_back(bit);
                    }
                    s.push(exp);
                }
                else {
                    string p = s.top();
                    s.pop();
                    string q = s.top();
                    s.pop();

                    string exp;
                    exp = "("+q+e+p+")";


                    vector<int> v;
                    m.insert(pair<string,vector<int>>(exp,v));

                    int length = m[p].size();
                    for (int i=0;i<length;i++){
                        int bit = BitOperation::operation(m[p][i],m[q][i],x);
                        m[exp].push_back(bit);
                    }
                    s.push(exp);
                }
            }
        }

        return m;
}
