// https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res="",temp="";
        
        int n= s.length();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                res=res+temp;
                temp="";
                res=res+' ';
            }
            else{
                temp=s[i]+temp;
            }
        }
        res=res+temp;
        
        return res;
    }
};