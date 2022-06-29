// https://leetcode.com/problems/count-asterisks/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        int n= s.length();
        int c=1,count=0;
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*' && c==1) c1++;
            if(s[i]=='|') c=1-c;
            // if(s[i]=='*' && c==0) c2++;
        }
        return c1;
    }
};