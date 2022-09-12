// https://leetcode.com/problems/most-frequent-even-element/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mp;
        int res=-1,ans=res;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                mp[nums[i]]++;
                if(mp[nums[i]] > res ) {
                    res=mp[nums[i]];
                    ans=nums[i];
                }
                else if(mp[nums[i]]==res){
                    if(ans> nums[i])    ans=nums[i];
                }
                
            }
        }
        
        return ans;
    }
};