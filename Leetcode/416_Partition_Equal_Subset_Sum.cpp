// https://leetcode.com/problems/partition-equal-subset-sum/
 
 
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sm=accumulate(nums.begin(),nums.end(),0);
        if(sm!=0) return false;
        else return solve(nums,sm/2);
        
    }
    bool solve(vector<int> &A, int B) {
        vector<vector<bool>> t(A.size()+1,vector<bool>(B+1,false));
        for(int i=0;i<=A.size();i++){
            t[i][0]=true;
        }
        for(int i=1;i<=A.size();i++){
            for(int j=1;j<=B;j++){
                if(A[i-1]<=j){
                    t[i][j]=t[i-1][j-A[i-1]] || t[i-1][j];
                }
                else t[i][j]=t[i-1][j];
            }
        }
        return t[A.size()][B];
    }
};