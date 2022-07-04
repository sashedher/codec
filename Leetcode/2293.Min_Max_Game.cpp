// https://leetcode.com/problems/min-max-game/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int x=nums.size();
        while(x!=1){
            vector<int> res(x/2,0);
            int n=res.size();
            
            for(int i=0;i<n;i++){
                if(i%2){
                    res[i]=max(nums[2*i],nums[2*i+1]);
                }
                else res[i]=min(nums[2*i],nums[2*i+1]);
            }
            // for(int y:res) cout<<y<<" ";
            // cout<<endl;

            x=x/2;
            nums.clear();
            nums=res;

        }
        return nums[0];
        
    }
};