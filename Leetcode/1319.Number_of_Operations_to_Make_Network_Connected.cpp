// https://leetcode.com/problems/number-of-operations-to-make-network-connected/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int makeConnected(int n, vector<vector<int>>& con) {
        int e=con.size();
        if(e<n-1) return -1;            //if number of nodes > edges(nodes-1) return -1; 
        int res=0;
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        
        for(int i=0;i<e;i++){
            adj[ con[i][0] ].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
        }
        
        for(int i=0;i<n;i++){                   // count number of connected components
            
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
                            q.push(adj[t][k]);
                        }
                    }
                }
                
                
            }
            
        }
        
        return res-1;        
    }
};