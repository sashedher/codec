// https://leetcode.com/problems/01-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(vector<vector<int>>& grid, queue<pair<int,int>> &q, int m, int n,vector<vector<int>>& vis){
        vector<pair<int,int>> v={{1,0},{0,1},{-1,0},{0,-1}};
        int tim=0;
        while(!q.empty()){
            int n1=q.size();
            tim++;
            for(int j=0;j<n1;j++){
                pair<int,int> t=q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int x= t.first+v[i].first;
                    int y= t.second+v[i].second;
                    if(x>=0 && x<m && y>=0 && y<n &&  vis[x][y]==0){
                        q.push({x,y});
                        vis[x][y]=1;
                        grid[x][y]=tim;
                    }
                }
            }
            
        }
        return;
    }
    
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int m=grid.size(),n= grid[0].size(),res=0;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
        if(!q.empty()) bfs(grid, q, m, n,vis);
        return grid;
    }
};