// https://leetcode.com/problems/rotate-array/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
      int n=nums.size();
        k=k%n;
        reverse(nums.begin(), nums.begin()+(n-k) );
        reverse(nums.begin()+(n-k),nums.end() );
        reverse(nums.begin(),nums.end());
        
//         for(int i=0;i<n-k;i++){
//             nums.insert(nums.end(),*nums.begin());
//             nums.erase(nums.begin());
//         }
        
        
    }
};