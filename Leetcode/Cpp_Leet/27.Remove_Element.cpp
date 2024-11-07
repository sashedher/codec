// https://leetcode.com/problems/remove-element/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size()==0) return 0;
        for(auto i=nums.begin();i<nums.end();){
            if(*i==val) nums.erase(i);
            else i++;
        }
        return nums.size();
    }
};