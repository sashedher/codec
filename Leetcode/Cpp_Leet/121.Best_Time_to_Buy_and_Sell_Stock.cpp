//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size(), res=INT_MIN,mn=INT_MAX;
        mn=prices[0];
        for(int i=1;i<n;i++){
            res=max(res,prices[i]-mn);
            mn=min(mn,prices[i]);
        }
        return res<0?0 :res;
    }
};