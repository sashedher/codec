// https://leetcode.com/problems/number-of-enclaves/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& grid, queue<pair<int,int>> &q, int m, int n){
        vector<pair<int,int>> v={{1,0},{0,1},{-1,0},{0,-1}};
        
        while(!q.empty()){
            int n1=q.size();
            
            for(int j=0;j<n1;j++){
                pair<int,int> t=q.front();
                q.pop();
                grid[t.first][t.second]=-1;
                for(int i=0;i<4;i++){
                    int x= t.first+v[i].first;
                    int y= t.second+v[i].second;
                    if(x>=0 && x<m && y>=0 && y<n &&  grid[x][y]==1){
                        q.push({x,y});
                        grid[x][y]=-1;

                    }
                }
            }
            
        }
        return ;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m=grid.size(),n= grid[0].size(),res=0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(grid[0][i]==1) {
                q.push({0,i});
                bfs(grid, q, m, n);
            }
            if(m>1 && grid[m-1][i]==1){
                q.push({m-1,i});
                bfs(grid, q, m, n);
            } 
            
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]==1) {
                q.push({i,0});
                bfs(grid, q, m, n);
            }
            if(n>1 && grid[i][n-1]==1) {
                q.push({i,n-1});
                bfs(grid, q, m, n);
            }
            
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) res++;
                    
            }
        }
        return res;
    }
};