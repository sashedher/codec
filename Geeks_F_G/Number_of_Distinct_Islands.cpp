// https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1

#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
  
    void bfs(vector<vector<int>>& grid, queue<pair<int,int>> &q, int m, int n,set<vector<pair<int,int>>>& shape){
        vector<pair<int,int>> v={{0,1},{1,0},{-1,0},{0,-1}},parts;
        int bx=q.front().first, by=q.front().second;
        while(!q.empty()){
            pair<int,int> t=q.front();
            q.pop();
            
            int tx=t.first-bx,ty=t.second-by;
            parts.push_back({tx,ty});

            for(int i=0;i<4;i++){
                int x= t.first+v[i].first;
                int y= t.second+v[i].second;
                if(x>=0 && x<m && y>=0 && y<n &&  grid[x][y]==1){
                    q.push({x,y});
                    grid[x][y]=0;
                }
            }
        }
        shape.insert(parts);
        return;
    }
    
    
    int countDistinctIslands(vector<vector<int>>& grid) {
        set<vector<pair<int,int>>> shape;
        int m=grid.size(),n= grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    bfs(grid,q,m,n,shape);
                }
            }
        }
        return shape.size();
        
    }
};