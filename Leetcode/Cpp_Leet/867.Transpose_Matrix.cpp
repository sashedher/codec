// https://leetcode.com/problems/transpose-matrix/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        // for(int i=0;i<m;i++){                     // for square matrix in O(1) space
        //     for(int j=0;j<n;j++){             
        //         if(i<j) swap(matrix[i][j],matrix[j][i]);
        //     }
        // }
        vector<vector<int>> res(n,vector<int>(m,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 res[j][i]=matrix[i][j];
            }
        }
        return res;
    }
    
};