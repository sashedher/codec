// https://leetcode.com/problems/toeplitz-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        if(m==1 || n==1) return true;
        int k=0;
        while(k<m){
            for(int i=k,j=0;i<m && j<n;i++,j++){
                if(mat[k][0]!=mat[i][j]) return false;
            }
            k++;
        }
        k=0;
        while(k<n){
            for(int i=0,j=k;i<m && j<n;i++,j++){
                if(mat[0][k]!=mat[i][j]) return false;
            }
            k++;
        }
        return true;
    }
};