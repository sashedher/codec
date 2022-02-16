//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low=prices[0],maxP=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<low) low=prices[i];
            else{
                maxP=max(maxP,prices[i]-low);
            }
        }
        return maxP;
    }
};