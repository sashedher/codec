// https://leetcode.com/problems/matrix-diagonal-sum/

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int pd=0,sd=0,n=mat.size();                                             
        for(int i=0;i<n;i++){
            pd+=mat[i][i];
            sd+=mat[i][n-i-1];
        }
        if(n%2) sd=sd-mat[n/2][n/2];
        return pd+sd;
    }
};