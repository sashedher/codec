// https://leetcode.com/problems/number-of-provinces/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<bool> vis(n,false);
        int res=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                res++;
                
                queue<int> q;
                q.push(i);
                vis[i]=true;
                while(!q.empty()){
                    int t=q.front();
                    q.pop();
                    
                    for(int j=0;j<n;j++){
                        if(adj[t][j]==1 && vis[ j ]==false){
                            q.push(j);
                            vis[ j ]=true;
                        }
                    }
                    
                }
                
            }
        }
        
        return res;
    }
};