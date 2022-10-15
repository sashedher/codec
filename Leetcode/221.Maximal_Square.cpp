// https://leetcode.com/problems/maximal-square/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m= matrix.size(),n=matrix[0].size(), res=INT_MIN;
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1') dp[i][j]=1;
                if(i!=0 && j!=0 && dp[i][j]==1) dp[i][j]=1+min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]});
                res=max(res, dp[i][j]);
            }
        }
        
        return res*res;
    }
};