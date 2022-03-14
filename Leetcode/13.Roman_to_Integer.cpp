// https://leetcode.com/problems/roman-to-integer/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> h;
        h.insert({'I',1});
        h.insert({'V',5});
        h.insert({'X',10});
        h.insert({'L',50});
        h.insert({'C',100});
        h.insert({'D',500});
        h.insert({'M',1000});
        
        int n=s.length();
        int num=h[s[n-1]];
        for(int i=n-2;i>=0;i--){
            if(h[s[i]]<h[s[i+1]]){
                num-=h[s[i]];
            }
            else num+=h[s[i]];
        }
        
        return num;
        
    }
};