// https://leetcode.com/problems/calculate-amount-paid-in-taxes/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double calculateTax(vector<vector<int>>& brac, int income) {
        double res=0;
        int n=brac.size(),i=0,curr=0;
        res=res+(brac[i][0]>income?income:brac[i][0])*brac[i][1]*1.0/100;
        // cout<<i<<" "<<curr<<" "<<res<<" "<<brac[i][0];
        // cout<<endl;
        curr=income-brac[i][0];
        i++;
        while(curr>0 && i<n){
            cout<<i<<endl;
            int x=brac[i][0]-brac[i-1][0];
            x=curr>x?x:curr;
            res=res+x*brac[i][1]*1.0/100;
            // cout<<curr<<" "<<res<<" "<<x<<endl;
            curr=curr-x;
            i++;
        }
        return res;
    }
};