// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

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


class Solution {
public:
    
    int makeConnected(int n, vector<vector<int>>& con) {
        int e=con.size();
        if(e<n-1) return -1;
        int res=0;
        DisJointSet ds(n);
        
        for(auto x:con) 
            ds.unionSize(x[0],x[1]);
        
        
        for(int i=0;i<ds.parent.size();i++){
            if(ds.parent[i] == i) res++;
        }
        
        
        return res-1;        
    }
};