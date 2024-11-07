// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int BinSearch(vector<int>& nums,int tar){
        int l=0,h=nums.size()-1,m;
        while(l<=h){
            m=l+(h-l)/2;
            if(nums[m]==tar) return m;
            else if(nums[m]>tar) h=m-1;
            else l=m+1;
        }
        return -1;
        
    }
    
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l,h,n=numbers.size();
        for(int i=0;i<n;i++){
            l=i;
            h=BinSearch(numbers,target-numbers[i]);
            if((h!=-1 && numbers[i]+numbers[h]==target)&& i!=h) break;
        }
        if(l<h) return {l+1,h+1};               // when elements are not distinct binary search will not-
        else return {h+1,l+1};                  //-always return upper bound of element
    }
};