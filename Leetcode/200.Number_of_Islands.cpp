// https://leetcode.com/problems/number-of-islands/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),res=0;
        vector<pair<int,int>> v={{0,-1},{0,1},{1,0},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    res++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j]='0';
                    while(!q.empty()){
                        pair<int,int> t=q.front();
                        q.pop();
                        for(int k=0;k<4;k++){
                            int  x,y;
                            x=v[k].first+t.first;
                            y=v[k].second+t.second;
                            if(x>=0 && x<n && y>=0 && y<m && grid[x][y]=='1'){
                                q.push({x,y});
                                grid[x][y]='0';
                            }
                        }
                        
                    }
                }
            }
        }
        
        return res;
    }
};