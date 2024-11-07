// https://leetcode.com/problems/n-queens/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int row,int col,vector<string> &ans,int n){
        for(int i=col;i>=0;i--){
            if(ans[row][i]=='Q') return false;
        }
        int i=row,j=col;
        while(i>=0 && j>=0){
            if(ans[i][j]=='Q') return false;
            i--,j--;
        }
        i=row,j=col;
        while(i<n && j>=0){
            if(ans[i][j]=='Q') return false;
            i++,j--;
        }
        return true;
    }
    void backtrack(int j,int n,vector<string> &ans, vector<vector<string>>& res){
        if(j==n){
            res.push_back(ans);
            return;
        }  
        for(int i=0;i<n;i++){
            if(isSafe(i,j,ans,n)){
                ans[i][j]='Q';
                backtrack(j+1,n,ans,res);
                ans[i][j]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> ans(n,string(n,'.'));
        vector<vector<string>> res;
        
        backtrack(0,n,ans,res);
        
        return res;
        
    }
};