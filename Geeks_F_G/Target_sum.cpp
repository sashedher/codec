// https://practice.geeksforgeeks.org/problems/target-sum-1626326450/1?ref=gcse

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findTargetSumWays(vector<int>& nums ,int target)  {
        target=abs(target);
        int sm=0;       
        for(int i=0;i<nums.size();i++){
            sm+=nums[i];
        }
        if((target+sm)%2!=0 || target>sm) return 0;
        return Countsubsetsum(nums,(target+sm)/2);
        
    }
    int Countsubsetsum(vector<int>& nums,int c){
        vector<vector<int>> t(nums.size()+1,vector<int>(c+1,0));
        for(int i=0;i<=nums.size();i++){
            t[i][0]=1;
        }
        for(int i=1;i<=nums.size();i++){
            for(int j=0;j<=c;j++){            // count from j=0 because if an array element contains zero  that sould be counted
                if(nums[i-1]<=j){
                    t[i][j]=t[i-1][j]+t[i-1][j-nums[i-1]];
                }
                else t[i][j]=t[i-1][j];
                
            }
        }
        return t[nums.size()][c];
    }
}; 