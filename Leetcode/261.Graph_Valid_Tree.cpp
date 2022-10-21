// https://leetcode.com/problems/graph-valid-tree/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool cyclecheck(int i, int par, vector<vector<int>>& adj,vector<bool> & vis){
      
        vis[i]=true;
  
        for(int j=0;j<adj[i].size();j++){
            if( vis[ adj[i][j] ]==false ){
                 if(cyclecheck(adj[i][j],i, adj, vis)) return true;
            }
            else if(adj[i][j]!=par) return true;
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>> &edges) {
        if(edges.size()!=n-1) return false;

        vector<bool>  vis(n,false);
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[ edges[i][1] ].push_back(edges[i][0]);
            adj[ edges[i][0] ].push_back(edges[i][1]);
        }

        for(int i=0;i<n;i++){
            if(vis[i]==false){
                if(cyclecheck(i,-1,adj,vis)) return false;
            }
        }
        return true;
    }
};