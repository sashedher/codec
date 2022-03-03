// https://leetcode.com/problems/arithmetic-slices/ - O(n) space
 
// 2 levels cosequite difference  and count cummulative zeros
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<int> l1,l2;
        int c=0;
        if(nums.size()<3) return 0;
        for(int i=0;i<nums.size()-1;i++){
            l1.push_back(nums[i+1]-nums[i]);
        }
        for(int i=0;i<l1.size()-1;i++){
            l2.push_back(l1[i+1]-l1[i]);
        }
        for(int i=0;i<l2.size();i++){
            if(l2[i]==0)
                c+=1;
        }
        return (c*(c+1))/2;
    }
};