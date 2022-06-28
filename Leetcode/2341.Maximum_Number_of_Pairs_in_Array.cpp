// https://leetcode.com/problems/maximum-number-of-pairs-in-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int c=1,e=0,o=0,n=nums.size();
        
        for(int x:nums) cout<<x<<" ";
        if(n==1) return {0,1};
        
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1]){
                c++;
            }
            else{
                e=e+c/2;
                o=o+c%2;
                c=1;
            }
        }
        if(c>1) {
                e=e+c/2;
                o=o+c%2;
                c=1;
        }
        if(nums[n-1]!=nums[n-2]) o++;
        
        return {e,o};
    }
};