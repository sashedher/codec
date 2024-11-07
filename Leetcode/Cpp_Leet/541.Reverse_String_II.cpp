// https://leetcode.com/problems/reverse-string-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        int n= s.length(),f=0;
        string res="",temp="",temp1="";
        int c=0;
        for(int i=0;i<n;i++){
            if( c==k ){
                if(f==0)    res=res+temp;
                else    res=res+temp1;
                
                f=1-f;
                temp=s[i];
                temp1=s[i];
                c=1;
                
            }
            else{
                c++;
                temp=s[i]+temp;
                temp1=temp1+s[i];
            }
        }
        if(f==0)    res=res+temp;
        else    res=res+temp1;
        return res;
    }
};