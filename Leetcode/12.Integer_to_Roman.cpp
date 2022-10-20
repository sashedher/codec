// https://leetcode.com/problems/integer-to-roman/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int n=num;
        string res="";
        vector<pair<string,int>> mp={{"M",1000},{"CM",900},{"D",500},{"CD",400},{"C",100},{"XC",90},{"L",50},{"XL",40},{"X",10},{"IX",9},{"V",5},{"IV",4},{"I",1}};
        
        for(int i=0;i<13;i++){
            while(mp[i].second<=num){
                num-=mp[i].second;
                res=res+mp[i].first;
            }
        }
        
        return res;
    }
};