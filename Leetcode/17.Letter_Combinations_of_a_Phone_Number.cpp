// https://leetcode.com/problems/letter-combinations-of-a-phone-number/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    void buildString(string dig,int i,map<char,string> ph,string temp){
        if(i==dig.length()){
            res.push_back(temp);
        }
        
        else{
        
            for(int j=0;j<ph[dig[i]].length();j++){
                temp.push_back(ph[dig[i]][j]);
                buildString(dig,i+1,ph,temp);
                temp.pop_back();
            }
            
        }
        
        
    }
    
    
    vector<string> letterCombinations(string dig) {
        map<char , string> ph;
        ph.insert({'2',"abc"});
        ph.insert({'3',"def"});
        ph.insert({'4',"ghi"});
        ph.insert({'5',"jkl"});
        ph.insert({'6',"mno"});
        ph.insert({'7',"pqrs"});
        ph.insert({'8',"tuv"});
        ph.insert({'9',"wxyz"});
        
        if(dig.length()==0) return {};
        string temp;
        
        buildString(dig,0,ph,temp);
        
        return res;  
    }
};