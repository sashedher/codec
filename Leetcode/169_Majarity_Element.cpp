// https://leetcode.com/problems/majority-element/  Accepted TC : O(n), SC : O(1)
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1,ele=nums[0];
        vector<int>::iterator it=nums.begin();
        it++;
        for(;it!=nums.end();it++){
            if(ele== *it){
                count++;
            }
            else count--;
            if(count==0){
                ele=*it;
                count=1;
            }
        }
        return ele;
    }
};