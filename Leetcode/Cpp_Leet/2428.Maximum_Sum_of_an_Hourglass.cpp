// https://leetcode.com/problems/maximum-sum-of-an-hourglass/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int res=INT_MIN;
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                int t= grid[i-1][j-1]+ grid[i-1][j]+grid[i-1][j+1]+grid[i][j]+ grid[i+1][j-1]+ grid[i+1][j] +grid[i+1][j+1];
                res=max(res,t);
            }
        }
        return res;
    }
};