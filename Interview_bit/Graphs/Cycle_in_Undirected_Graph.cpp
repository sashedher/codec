// https://www.interviewbit.com/problems/cycle-in-undirected-graph/

#include<bits/stdc++.h>
using namespace std;

// use parent node and prev node is not equal to parent then cycle is present in graph

class Solution{
public: 

    int solve(int A, vector<vector<int> > &B) {
        int e= B.size();
        vector<vector<int>> adj(A+1);
        vector<bool> vis(A+1,false);
        
        for(int i=0;i<e;i++){
            adj[ B[i][0] ].push_back( B[i][1] );
            adj[ B[i][1] ].push_back( B[i][0] );
        }
        
        for(int i=1;i<=A;i++){
            if(vis[i]==false){

                queue<pair<int,int>> q;
                q.push({i,-1});
                vis[i]=true;
                while(!q.empty()){
                    pair<int,int> t=q.front();
                    q.pop();
                    
                    for(int k=0;k<adj[t.first].size();k++){
                        
                        if(vis[ adj[t.first][k] ]==false){
                            q.push( {adj[t.first][k] , t.first} );
                            vis[ adj[t.first][k] ]=true;
                        }
                        else if(adj[t.first][k]!=t.second) return 1;
                    }
                }
                
            }
        }
        return 0;
    }

};