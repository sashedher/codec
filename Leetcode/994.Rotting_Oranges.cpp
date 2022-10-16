// https://leetcode.com/problems/rotting-oranges/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(vector<vector<int>>& grid, queue<pair<int,int>> &q, int m, int n){
        vector<pair<int,int>> v={{1,0},{0,1},{-1,0},{0,-1}};
        int tim=0;
        while(!q.empty()){
            int n1=q.size();
            tim++;
            for(int i=0;i<n1;i++){
                pair<int,int> t=q.front();
                q.pop();

                for(int i=0;i<4;i++){
                    int x= t.first+v[i].first;
                    int y= t.second+v[i].second;
                    if(x>=0 && x<m && y>=0 && y<n &&  grid[x][y]==1){
                        q.push({x,y});
                        grid[x][y]=2;

                    }
                }
            }
            
        }
        return tim-1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n= grid[0].size(),res=0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        if(!q.empty()) res=bfs(grid, q, m, n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) return -1;
                    
            }
        }
      
        return res;
    }
};