// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        int e=edges.size();
        
        int res=0;
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        vector<int> count;
        for(int i=0;i<e;i++){
            adj[ edges[i][0] ].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for(int i=0;i<n;i++){
            res=0;
            if(vis[i]==false){
                res++;
                
                queue<int> q;
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int t=q.front();
                    q.pop();
                    for(int k=0;k<adj[t].size();k++){
                        if(vis[ adj[t][k] ] == false ){
                            vis[ adj[t][k] ] = true;
                            res++;
                            q.push(adj[t][k]);
                        }
                    }
                }
                
                
            }
            if(res!=0) count.push_back(res);
            
        }
        // for(int x:count) cout<<x<<" ";
        // cout<<endl;
        int n1= count.size();
        long long sm=0,sq=0;
        for(int i=0;i<n1;i++){
            sm+=count[i];
            sq+=(long)count[i]*(long)count[i];
        }
        sm=sm*sm-sq;
        return sm/2;      
    }
};