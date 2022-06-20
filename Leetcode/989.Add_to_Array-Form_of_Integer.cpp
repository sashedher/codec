// https://leetcode.com/problems/add-to-array-form-of-integer/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> kv,res;
        while(k>0){
            kv.insert(kv.begin(),k%10);
            k/=10;
        }
        int l1=num.size(),l2=kv.size(),c=0,s=0,x=0,y=0;
        for(int i=l1-1,j=l2-1;(i>=0 || j>=0) || c!=0 ; i--,j--){
            x= (i>=0) ? num[i] : 0;
            y= (j>=0) ? kv[j]  : 0;
            
            s=x+y+c;
            c=s/10;
            s=s%10;
            res.insert(res.begin(),s);
        }
        return res;
    }
};