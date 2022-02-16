//  https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ alternative code for minimum difference
//  controller never entered into else block so this code does not work if array is sorted
 
#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    int minProfit(vector<int>& prices) {
        int high=prices[0],minP=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>high) high=prices[i];
            else{
                minP=max(minP,prices[i]-high);
            }
        }
        return minP;
    }
};