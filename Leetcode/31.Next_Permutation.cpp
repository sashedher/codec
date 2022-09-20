// https://leetcode.com/problems/next-permutation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind=-1,i;
        int n=nums.size();
        for( i=n-1;i>=1;i--){
            if(nums[i-1]<nums[i]){              //find find 1st decreasing element from right
                ind=i-1;
                break;
            }
        }
        if(ind>=0){                             //swap that 1st decreaseing element with next smallest greater element to its right
            int j=n-1;
            while(nums[j]<=nums[ind]) j--;
            swap(nums[ind],nums[j]);
           
        }
        
        i=ind+1;
        int j=n-1;
        while(i<j){                         //after swapping reverse entire subarray
            swap(nums[i++],nums[j--]);
        }
    }
};