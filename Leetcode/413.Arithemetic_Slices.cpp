// https://leetcode.com/problems/arithmetic-slices/ - O(1) space
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int c=0,s=0;
        if(nums.size()<3) return 0;
        
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i+1]-nums[i]== nums[i+2]-nums[i+1])  c+=1;
            else {
                s=s+(c*(c+1))/2;
                c=0;
            }
        }
        
        s=s+(c*(c+1))/2;      
        
        return s;
    }
};