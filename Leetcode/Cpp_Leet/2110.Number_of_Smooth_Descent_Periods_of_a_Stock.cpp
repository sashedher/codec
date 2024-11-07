// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long c=0,s=0;
        int n=prices.size();
        for(int i=0;i<n-1;i++){
            if(prices[i]-prices[i+1]==1) s=s+ ++c;
            else c=0;
        }
        return s+n;
        
    }
};