// https://www.interviewbit.com/problems/path-in-directed-graph/

// either use stack-DFS or Queue-BFS
#include<bits/stdc++.h>
using namespace std;

class Solution{
public: 
    int solve(int A, vector<vector<int> > &B) {
        stack<int> q;
        // int adjm[A+1][A+1]={0};
        int m=B.size();
        vector<int> vis(A+1,0);
        vector<vector<int>> adj(A+1);
        
        for(int i=0;i<m;i++){
            adj[B[i][0]].push_back(B[i][1]);
        }
        q.push(1);
        vis[1]=1;
        
        while(!q.empty()){
            int t=q.top();
            q.pop();
            for(int i=0;i<adj[t].size();i++){
                if(vis[adj[t][i]]==0){
                    vis[adj[t][i]]=1;
                    q.push(adj[t][i]);
                    if(adj[t][i]==A) return 1;
                }
            }
        }
        
        return 0;
    }


};