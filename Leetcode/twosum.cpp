// https://leetcode.com/problems/two-sum/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> op;
        vector<int> res(2);
        for(int i=0;i<nums.size();i++){
            op.insert({nums[i],i});
        }
        for(int i=0;i<nums.size();i++){
            if(op.find(target-nums[i])!=op.end() && i!=op.find(abs(target-nums[i]))->second){
                res[0]=i;
                res[1]=op.find(target-nums[i])->second;
                   break;
            }
        }
        return res;
    }
};