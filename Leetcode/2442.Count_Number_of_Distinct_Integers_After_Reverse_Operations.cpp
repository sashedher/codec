// https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rev(int n){
        int r=0;
        while(n>0){
            r=r*10+n%10;
            n/=10;
        }
        return r;
    }
    int countDistinctIntegers(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums.push_back(rev(nums[i]));
        }
        
        set<int> s(nums.begin(), nums.end());
        
        return s.size();
    }
};