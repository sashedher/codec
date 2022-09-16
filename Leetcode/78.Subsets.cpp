// https://leetcode.com/problems/subsets/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void subseq(vector<int> &v, int n,vector<int> &ans,vector<vector<int>> &res){           // store all subsequences/subsets
        if(n<0){
            res.push_back(ans) ;
            return;
        } 
        subseq(v,n-1,ans,res);   // without considering the current element
        ans.push_back(v[n]);
        subseq(v,n-1,ans,res);   // with considering the current element
        ans.pop_back();  

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ans;
        subseq(nums,nums.size()-1,ans,res);
        return res;
    }
};