// https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m= grid.size(), n = grid[0].size();
        
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        
        queue<vector<int>> q;
        if(grid[0][0]==0){
            q.push({0,0,1});
            dis[0][0]=1;
        } 
        
        while(!q.empty()){
            auto t=q.front();
            q.pop();
            int x=t[0], y=t[1], d=t[2];
            
            if(x==m-1 && y==n-1) return d;
            
            for(int i=-1;i<2;i++){
                for(int j=-1;j<2;j++){
                    int x1=x+i, y1=y+j;
                    if(x1>=0 && y1>=0 && x1<m && y1<n && grid[x1][y1]==0){
                        if(dis[x1][y1]>d+1){
                            q.push({x1,y1,d+1});
                            dis[x1][y1]=d+1;
                        }    
                        
                    }
                }
            }
        }
        return -1;
    }
};