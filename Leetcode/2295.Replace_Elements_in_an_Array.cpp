// https://leetcode.com/problems/replace-elements-in-an-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> mp;
        int n= nums.size();
        
        for(int i=0;i<n;i++){
            mp[nums[i]]=i;
        }
        
        n=operations.size();
        for(int i=0;i<n;i++){                                                                       //delete old element and update new element with same index
            unordered_map<int,int> :: iterator it=mp.find(operations[i][0]);
            int x= it->second;
            mp.erase(it);
            mp[operations[i][1]]=x;
        }
        
        // n=nums.size();
        unordered_map<int,int> :: iterator it;                      // replace all elements based on index(value in map) on nums vector to get final vector
        for(it=mp.begin(); it!=mp.end() ;it++){
            nums[it->second]=it->first;
        }
        
        return nums;
    }
};