// https://leetcode.com/problems/plus-one/ 
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& dig) {
        int n=dig.size();
        int s=0,c=1;
        for(int i=n-1;i>=0;i--){
            s=dig[i]+c;
            dig[i]=s%10;
            c=s/10;
            if(c==0) break;
        }
        if(c>0) dig.insert(dig.begin(),c);
        return dig;
    }
};