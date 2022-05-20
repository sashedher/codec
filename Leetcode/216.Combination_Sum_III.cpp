// https://leetcode.com/problems/combination-sum-iii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> res;
    void Backtrack(vector<int> cand,int target,vector<int> &ans,int ind,int k){
        if(ind>cand.size()) return ;
        
        if(target==0){
            // cout<<"res size="<<res.size()<<endl;
            if(ans.size()==k)  res.push_back(ans);
            return ;
        }
        
        if(target<0)    return ;
        
        for(int i=ind;i<cand.size();i++){
                ans.push_back(cand[i]);
                // for(int x:ans) cout<<x<<" ";
                // cout<<"\n"<<target-cand[i]<<" "<<i+1<<endl;
                Backtrack(cand,target-cand[i],ans,i+1,k);
                ans.pop_back();   
        }
                 
                
            
        
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cand={1,2,3,4,5,6,7,8,9};
        // for(int x: cand) cout<<x<<" ";
        vector<int> ans;
        Backtrack(cand,n,ans,0,k);
        return res;
    }
};