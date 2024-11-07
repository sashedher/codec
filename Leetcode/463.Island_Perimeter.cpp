// https://leetcode.com/problems/island-perimeter/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        vector<pair<int,int>> v={{1,0},{-1,0},{0,1},{0,-1}};
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    if(i==0 || j==0 || i==m-1 || j==n-1) ans+=(i==0)+(j==0)+(i==m-1)+(j==n-1);
                    if(i-1>=0 && grid[i-1][j]==0) ans++;
                    if(j-1>=0 && grid[i][j-1]==0) ans++;
                    if(i+1<m && grid[i+1][j]==0) ans++;
                    if(j+1<n && grid[i][j+1]==0) ans++;
                    
                }
            }
        }
        return ans;
    }
};