// https://leetcode.com/problems/3sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        map<int,int> op;
        vector<vector<int>> res(0);
        int k=0;
        for(int i=0;i<nums.size();i++){
            op.insert({nums[i],i});
        }
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(op.find(-nums[i]-nums[j])!=op.end() && j!=op.find(-nums[i]-nums[j])->second){
                // vector<int> v;
                // v.push_back(i);
                // v.push_back(j);
                // v.push_back(op.find(-nums[i]-nums[j])->second);
                res.push_back({i,j,op.find(-nums[i]-nums[j])->second});
                k++;    
            }
                
            }
            
        }
        return res;
    }
};