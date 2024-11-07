// https://leetcode.com/problems/subarray-sum-equals-k/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),res=0;
        vector<int> presm(n);
        unordered_map<int,int > mp;
        presm[0]=nums[0];
        for(int i=1;i<n;i++) presm[i]=presm[i-1]+nums[i];
        
        for(int i=0;i<n;i++){
            int t=presm[i]-k;
            res=res+mp[t];
            if(presm[i]==k) res++;
            mp[presm[i]]++;
        }
        return res;
    }
};