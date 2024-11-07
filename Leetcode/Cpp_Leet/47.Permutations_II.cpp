// https://leetcode.com/problems/permutations-ii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    set<string> res;
    int n=0;
    void Backtrack(vector<int> &nums,int index){
        if( nums.size()==index ){
            string tmp="";
            for(int x: nums) tmp.push_back(x+'0');
            // cout<<tmp<<endl;
            res.insert(tmp);
            return;
        }
        
            for(int i=index;i<nums.size();i++){
                // cout<<i<<" "<<index<<endl;
                swap(nums[i],nums[index]);
                Backtrack(nums,index+1);
                swap(nums[i],nums[index]);

        
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        Backtrack(nums,0);
        vector<vector<int>> result;
        for(set<string> :: iterator it=res.begin();it!=res.end();it++){
            string tp=*it;
            // cout<<tp<<endl;
            vector<int> ans;
            for(int i=0;i<tp.length();i++) ans.push_back(tp[i]-'0');
            result.push_back(ans);
        }
        
        
        
        return result;
    }
};