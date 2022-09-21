// https://leetcode.com/problems/permutations/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    vector<vector<int>> res;
   
    void Backtrack(vector<int> &nums,int index){
        if( nums.size()==index ){
            res.push_back(nums);
        }
       
        else{
            for(int i=index;i<nums.size();i++){
                swap(nums[i],nums[index]);
                Backtrack(nums,index+1);
                swap(nums[i],nums[index]);

            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        Backtrack(nums,0);
        return res;
        
    }
};