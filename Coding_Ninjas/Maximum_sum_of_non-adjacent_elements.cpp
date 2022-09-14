// https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0

#include<bits/stdc++.h>
using namespace std;

int rec(vector<int> & v, int i){
    if(i<0) return 0; 
    return max( v[i]+rec(v,i-2), rec(v,i-1) );
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size();
    return rec(nums,nums.size()-1);
}