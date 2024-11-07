// https://leetcode.com/problems/surrounded-regions/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<char>>& grid, queue<pair<int,int>> &q, int m, int n){
        vector<pair<int,int>> v={{1,0},{0,1},{-1,0},{0,-1}};
        
        while(!q.empty()){
            int n1=q.size();
            
            for(int j=0;j<n1;j++){
                pair<int,int> t=q.front();
                q.pop();
                grid[t.first][t.second]='-';
                for(int i=0;i<4;i++){
                    int x= t.first+v[i].first;
                    int y= t.second+v[i].second;
                    if(x>=0 && x<m && y>=0 && y<n &&  grid[x][y]=='O'){
                        q.push({x,y});
                        grid[x][y]='-';

                    }
                }
            }
            
        }
        return ;
    }
    
    void solve(vector<vector<char>>& grid) {
        int m=grid.size(),n= grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(grid[0][i]=='O') {
                q.push({0,i});
                bfs(grid, q, m, n);
            }
            if(m>1 && grid[m-1][i]=='O'){
                q.push({m-1,i});
                bfs(grid, q, m, n);
            } 
            
        }
        for(int i=0;i<m;i++){
            if(grid[i][0]=='O') {
                q.push({i,0});
                bfs(grid, q, m, n);
            }
            if(n>1 && grid[i][n-1]=='O') {
                q.push({i,n-1});
                bfs(grid, q, m, n);
            }
            
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='O') grid[i][j]='X';
                if(grid[i][j]=='-') grid[i][j]='O';
                    
            }
        }
    }
};