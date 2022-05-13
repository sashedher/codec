// https://leetcode.com/problems/combinations/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> res;
    
    void Backtrack(int n,int k,int index,vector<int> ans){
        if(ans.size()==k) res.push_back(ans);
        else{
            for(int i=index;i<=n;i++){
                ans.push_back(i);
                Backtrack(n,k,i+1,ans);
                ans.pop_back();
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        Backtrack(n,k,1,ans);
        return res;
    }
};