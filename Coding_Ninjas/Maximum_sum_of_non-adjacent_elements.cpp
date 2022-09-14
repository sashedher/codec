// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

int rec(vector<int> & v, int i){
    if(i<0) return 0; 
    return max( v[i]+rec(v,i-2), rec(v,i-1) );
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    int prev2=0,prev1=0,curr=0;
    prev2=nums[0];
    prev1=max(nums[0],nums[1]);
    for(int i=2;i<n;i++){
         curr=max(nums[i]+prev2, prev1);
         prev2=prev1;
        prev1=curr;
        
    }
    return prev1;
//     return rec(nums,nums.size()-1);
}