// https://leetcode.com/problems/count-square-submatrices-with-all-ones/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size(), n= matrix[0].size();
        int res=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
    
                if(i!=0 && j!=0 && matrix[i][j]==1) matrix[i][j]=1+min({matrix[i-1][j-1], matrix[i-1][j], matrix[i][j-1]});
                res+=matrix[i][j];
    
            }
        }
        
        return res;
    }
};