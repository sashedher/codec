

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfscycle(vector<vector<int>>& graph, int x, vector<int>& vis, vector<int>& pathvis,set<int>& sf){
        vis[x]=1;
        pathvis[x]=1;
        for(int nd:graph[x]){
            if(vis[nd]==0){
                if(dfscycle(graph,nd,vis,pathvis,sf)) return true;
            }
            else if(pathvis[nd]==1) return true;
        }
        sf.insert(x);                                   // only node is safe node because any of its subsequent nodes are included in cycle
        pathvis[x]=0;                                   //path vis not modified if we detect a cycle simply it will return from for loop.
        return false;                                   //so if any node leads to node which is path visited then it is not included beacause it will return from for loop
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        set<int> sf;
        vector<int> vis(n,0),pathvis(n,0);
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                dfscycle(graph,i,vis,pathvis,sf);
            }
        }
        
        return {sf.begin(),sf.end()};
    }
};