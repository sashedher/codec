// https://leetcode.com/problems/number-of-islands/

#include<bits/stdc++.h>
using namespace std;

class DisJointSet{
public:
    vector<int> rank,size,parent;
    
    DisJointSet(int n){
        rank.resize(n,0);
        parent.resize(n,0);
        size.resize(n,1);
        for(int i = 0 ;i<n; i++){
            parent[i]=i;
        }
    }
    int findParent(int u){
        if(u==parent[u]) return u;
        else return parent[u] = findParent(parent[u]);
    }
    
    void unionRank(int u, int v){
        int ult_u=findParent(u);
        int ult_v=findParent(v);
        if(ult_u == ult_v) return;
        if(rank[ult_u] < rank[ult_v] ){
            parent[ult_u]= ult_v;
        }
        if(rank[ult_v] < rank[ult_u] ){
            parent[ult_v]= ult_u;
        }
        else{
            parent[ult_v]= ult_u;
            rank[ult_u]+=1;
        }
    }
    
    void unionSize(int u, int v){
        int ult_u=findParent(u);
        int ult_v=findParent(v);
        if(ult_u == ult_v) return;
        
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        
    }
    
};

void solve(int i,int j, DisJointSet& ds,vector<vector<char>>& grid,int n, int m){
    vector<pair<int,int>> v={{0,1},{1,0},{0,-1},{-1,0}};
    queue<pair<int,int>> q;
    q.push({i,j});
    int r= i*m+j;
    
    while(!q.empty()){
        auto it=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int x= it.first + v[i].first;
            int y= it.second + v[i].second;
            
            if(x>=0 && y>=0 && x<n && y<m && grid[x][y]=='1'){
                grid[x][y]='-';
                q.push({x,y});
                ds.unionSize(r, x*m+y);
            }
            
        }
    }
}

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size(),res=0;
        
        DisJointSet ds(n*m);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    grid[i][j]='0';
                    solve(i,j,ds,grid,n,m);
                }
                else if(grid[i][j]='0'){            // remove that node from DisJointSet by making parent =-1 
                    ds.parent[i*m+j]=-1;
                }
            }
        }
        for(int i=0;i<ds.parent.size();i++){
            if(ds.parent[i] == i) res++;
        }
        
        return res;
    }
};