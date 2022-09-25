// https://leetcode.com/problems/unique-paths-iii/submissions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int solve(vector<vector<int>>& grid,int i,int j,int m,int n,int count,int pl){
        if(i<0 || j<0 || i==m || j==n|| grid[i][j]==5 || grid[i][j]==-1) return 0;
        if(grid[i][j]==2){
            if(pl-1==count) return 1;
            else return 0;
        } 
        pl++;
        int x=grid[i][j];
        grid[i][j]=5;
        int l=solve(grid,i,j-1,m,n,count,pl);
        int r=solve(grid,i,j+1,m,n,count,pl);
        int u=solve(grid,i-1,j,m,n,count,pl);
        int d=solve(grid,i+1,j,m,n,count,pl);
        grid[i][j]=x;
        
        return l+r+u+d;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size(),n= grid[0].size();
        pair<int,int> start;
        int count=0;
        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    start.first=i;
                    start.second=j;
                }
               if(grid[i][j]==0) count++;
            } 
        }
        return solve(grid,start.first,start.second,m,n,count,0);
    }
};