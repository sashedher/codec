// https://leetcode.com/problems/removing-stars-from-a-string/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeStars(string s) {
        
        int n=s.length();
        string res="";
        for(int i=0;i<n;i++){
            
            if(s[i]=='*')   res.pop_back();
            
            else res.push_back(s[i]);
            
        }
       
        
        return  res;       
    }
};
